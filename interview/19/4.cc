#include <list>
#include <unordered_map>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;
class LRUCache {
  size_t m_capacity;
  unordered_map<int, list<pair<int, int>>::iterator> m_map;
  list<pair<int, int>> m_list;

public:
  LRUCache(size_t capacity) : m_capacity(capacity) {}
  int get(int key) {
    auto found_iter = m_map.find(key);
    if (found_iter == m_map.end()) return -1;
    m_list.splice(m_list.begin(), m_list, found_iter->second);
    return found_iter->second->second;
  }
  void set(int key, int value) {
    auto found_iter = m_map.find(key);
    if (found_iter != m_map.end()) {
      m_list.splice(m_list.begin(), m_list, found_iter->second);
      found_iter->second->second = value;
      return;
    }
    if (m_map.size() == m_capacity) {
      int key_to_del = m_list.back().first;
      m_list.pop_back();
      m_map.erase(key_to_del);
    }
    m_list.emplace_front(key, value);
    m_map[key] = m_list.begin();
  }
};
