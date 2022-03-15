#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

struct key_value {
  int key;
  int value;
};

class LRUCache {
  list<key_value> lst;
  using Iter = decltype(lst)::iterator;
  unordered_map<int, Iter> mp;
  int cap;

public:
  LRUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    if (mp.find(key) == mp.end()) { return -1; }
    auto old_iter = mp.at(key);
    auto const value = old_iter->value;
    erase(old_iter);
    push(key, value);
    return value;
  }

  void put(int key, int value) {
    if (mp.find(key) == mp.end()) {
      push(key, value);
    } else {
      auto old_iter = mp.at(key);
      erase(old_iter);
      push(key, value);
    }
    if (size(mp) > cap) { erase(begin(lst)); }
  }

private:
  void push(int key, int value) {
    lst.push_back({ key, value });
    mp[key] = prev(end(lst));
  }

  void erase(Iter iter) {
    mp.erase(iter->key);
    lst.erase(iter);
  }
};
