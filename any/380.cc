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
public:
  RandomizedSet() {}

  bool insert(int val) {
    if(mp.find(val) != mp.end()){
      return false;
    }
    mp[val] = size(arr);
    arr.push_back(val);
    return true;
  }

  bool remove(int val) {
    if(mp.find(val) == mp.end()) return false;
    int last = arr.back();
    mp[last] = mp[val];
    arr[mp[val]] = last;
    arr.pop_back();
    mp.erase(val);
    return true;
  }

  int getRandom() {
    return arr[rand() % size(arr)];
  }
private:
  vector<int> arr;
  unordered_map<int, int> mp;
};
