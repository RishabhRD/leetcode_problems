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

class Solution {
public:
  bool divideArray(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (int num : nums) { mp[num]++; }
    for (auto [k, v] : mp) {
      if (v % 2 != 0) return false;
    }
    return true;
  }
};
