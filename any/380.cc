#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

class RandomizedSet {
  unordered_map<int, int> mp;
  vector<int> ele;

public:
  RandomizedSet() {}

  bool insert(int val) {
    if (mp.find(val) != mp.end()) return false;
    mp[val] = size(ele);
    ele.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (mp.find(val) == mp.end()) return false;
    auto const last_ele = ele[size(ele) - 1];
    auto const idx = mp[val];
    swap(ele[idx], ele[size(ele) - 1]);
    ele.pop_back();
    mp[last_ele] = idx;
    mp.erase(val);
    return true;
  }

  int getRandom() { return ele[rand() % size(ele)]; }
};
