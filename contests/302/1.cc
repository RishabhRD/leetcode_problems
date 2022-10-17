#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> numberOfPairs(std::vector<int>& nums) {
    std::unordered_map<int, int> mp;
    for (auto e : nums) ++mp[e];
    int n1 = 0;
    int n2 = 0;
    for (auto [k, v] : mp) {
      n1 += (v / 2);
      n2 += (v % 2);
    }
    return std::vector({n1, n2});
  }
};
