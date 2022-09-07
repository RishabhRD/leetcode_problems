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
  int maxAbsoluteSum(std::vector<int>& nums) {
    auto const n = std::size(nums);
    int local_max_sum = nums[0];
    int global_max_sum = nums[0];

    int local_min_sum = nums[0];
    int global_min_sum = nums[0];
    for (int i = 1; i < n; ++i) {
      auto const ele = nums[i];

      local_max_sum = std::max(local_max_sum + ele, ele);
      local_min_sum = std::min(local_min_sum + ele, ele);

      global_max_sum = std::max(global_max_sum, local_max_sum);
      global_min_sum = std::min(global_min_sum, local_min_sum);
    }

    return std::max(global_max_sum, std::abs(global_min_sum));
  }
};
