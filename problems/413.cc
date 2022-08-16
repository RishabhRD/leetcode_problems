#include <algorithm>
#include <array>
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
  int numberOfArithmeticSlices(std::vector<int>& nums) {
    auto const n = std::size(nums);
    if (n < 3) return 0;
    auto prev_diff = nums[1] - nums[0];
    int num_sub_windows{};
    int total_windows{};
    for (int high = 2; high < n; ++high) {
      auto const cur_diff = nums[high] - nums[high - 1];
      if (cur_diff == prev_diff) {
        ++num_sub_windows;
      } else {
        num_sub_windows = 0;
        prev_diff = cur_diff;
      }
      total_windows += num_sub_windows;
    }
    return total_windows;
  }
};
