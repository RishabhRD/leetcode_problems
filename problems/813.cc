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

template <typename Iter>
double dfs(Iter begin, Iter low, Iter high, int k,
           std::vector<std::vector<double>>& dp) {
  auto const range_size = std::distance(low, high);
  if (low == high) return 0;
  if (k > range_size) {
    return 0;
  }
  if (k == 1) {
    return std::accumulate(low, high, 0.0) / range_size;
  }
  auto const cur_idx = std::distance(begin, low);
  if (dp[cur_idx][k] >= 0) return dp[cur_idx][k];
  double cur_sum = 0;
  int cur_size = 0;
  double ans = 0;
  for (auto cur_itr = low; cur_itr < high; ++cur_itr) {
    auto const ele = *cur_itr;
    cur_sum += ele;
    ++cur_size;
    auto const cur_avg = cur_sum / cur_size;
    ans = std::max(ans,
                   cur_avg + dfs(begin, std::next(cur_itr), high, k - 1, dp));
  }
  return dp[cur_idx][k] = ans;
}

class Solution {
 public:
  double largestSumOfAverages(std::vector<int>& nums, int k) {
    auto const n = std::size(nums);
    std::vector dp(n, std::vector(k + 1, -1.0));
    return dfs(std::cbegin(nums), std::cbegin(nums), std::cend(nums), k, dp);
  }
};
