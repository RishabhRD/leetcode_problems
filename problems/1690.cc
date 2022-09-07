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

int dfs(int low, int high, std::vector<int> const& stones,
        std::vector<std::vector<std::optional<int>>>& dp) {
  if (low >= high) return 0;

  if (dp[low][high].has_value()) {
    return dp[low][high].value();
  }

  auto const ll_s = stones[low + 1] + dfs(low + 2, high, stones, dp);
  auto const lr_s = stones[high] + dfs(low + 1, high - 1, stones, dp);
  auto const rl_s = stones[low] + dfs(low + 1, high - 1, stones, dp);
  auto const rr_s = stones[high - 1] + dfs(low, high - 2, stones, dp);

  dp[low][high] = std::max(std::min(ll_s, lr_s), std::min(rl_s, rr_s));
  return dp[low][high].value();
}

class Solution {
 public:
  int stoneGameVII(std::vector<int>& stones) {
    auto const n = std::size(stones);
    std::vector dp(n, std::vector(n, std::optional<int>{}));
    auto const res = dfs(0, n - 1, stones, dp);
    return res;
  }
};
