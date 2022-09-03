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
  bool findSubarrays(std::vector<int>& nums) {
    std::unordered_map<int, int> mp;
    for (int i = 0; i < std::size(nums) - 1; ++i) {
      auto const sum = nums[i] + nums[i + 1];
      ++mp[sum];
      if (mp[sum] == 2) return true;
    }
    return false;
  }
};
