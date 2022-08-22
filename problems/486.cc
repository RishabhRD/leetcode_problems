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

int max_score(int low, int high, std::vector<int> const& nums,
              std::vector<std::vector<int>>& dp) {
  if (low > high) return 0;
  if (dp[low][high] >= 0) return dp[low][high];
  return dp[low][high] = std::max(
             nums[low] + std::min(max_score(low + 2, high, nums, dp),
                                  max_score(low + 1, high - 1, nums, dp)),
             nums[high] + std::min(max_score(low, high - 2, nums, dp),
                                   max_score(low + 1, high - 1, nums, dp)));
}

class Solution {
 public:
  bool PredictTheWinner(std::vector<int>& nums) {
    auto const n = std::size(nums);
    auto const sum = std::accumulate(std::cbegin(nums), std::cend(nums), 0);
    auto const target = (sum + 1) / 2;
    std::vector dp(n, std::vector(n, -1));
    return max_score(0, n - 1, nums, dp) >= target;
  }
};
