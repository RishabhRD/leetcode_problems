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

int max_subarray_target_len(std::vector<int> const& nums, int t) {
  if (t < 0) return -1;
  int ans = -1;
  int low = 0;
  int cur_sum = 0;
  for (int high = 0; high < std::size(nums); ++high) {
    cur_sum += nums[high];
    while (cur_sum > t) {
      cur_sum -= nums[low];
      ++low;
    }
    if (cur_sum == t) {
      ans = std::max(ans, high - low + 1);
    }
  }
  return ans;
}

class Solution {
 public:
  int minOperations(std::vector<int>& nums, int x) {
    auto const sum = std::reduce(std::begin(nums), std::end(nums), 0);
    auto const subarray = max_subarray_target_len(nums, sum - x);
    if (subarray == -1)
      return -1;
    else
      return std::size(nums) - subarray;
  }
};
