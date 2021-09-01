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
  std::list<pair<int, int>> lst;
  unordered_map<int, decltype(lst)::iterator> mp;
  int cap;

  private:
  inline void insert(int key, int val) {
    lst.emplace_back(key, val);
    mp[key] = prev(end(lst));
  }

  inline void remove(int key) {
    lst.erase(mp[key]);
  }

  inline bool contains(int key) { return mp.find(key) != mp.end(); }

public:
  LRUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    if (!contains(key)) { return -1; }
    int val = mp[key]->second;
    remove(key);
    insert(key, val);
    return val;
  }

  void put(int key, int value) {
    if (contains(key)) { remove(key); }
    insert(key, value);
    if (lst.size() > cap) {
      auto old_key = lst.front().first;
      mp.erase(old_key);
      lst.pop_front();
    }
  }
};
