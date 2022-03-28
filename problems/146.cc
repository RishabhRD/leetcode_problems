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
  struct node {
    int key;
    int val;
  };
  int cap;
  using lst_type = list<node>;
  unordered_map<int, lst_type::iterator> mp;
  lst_type lst;

public:
  LRUCache(int capacity) : cap{ capacity } {}

  int get(int key) {
    if (!contains(key)) { return -1; }
    auto [k, v] = *mp[key];
    shift_to_end(key);
    return v;
  }

  void put(int key, int val) {
    if (contains(key)) {
      shift_to_end(key);
      lst.back() = { key, val };
    } else {
      push_to_end(key, val);
      if (size(lst) > cap) { del_first(); }
    }
  }

public:
  void del_first() {
    auto [k, v] = lst.front();
    lst.pop_front();
    mp.erase(k);
  }

  bool contains(int key) { return mp.find(key) != mp.end(); }

  void shift_to_end(int key) {
    auto itr = mp[key];
    auto [k, v] = *itr;
    lst.erase(itr);
    push_to_end(k, v);
  }

  void push_to_end(int k, int v) {
    lst.push_back({ k, v });
    mp[k] = prev(end(lst));
  }
};
