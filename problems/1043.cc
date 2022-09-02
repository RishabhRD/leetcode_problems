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

int max_sum(int cur, std::vector<int> const& arr, int k, std::vector<int>& dp) {
  if (cur >= std::size(arr)) return 0;
  if (dp[cur] != -1) return dp[cur];
  auto cur_max = 0;
  auto res = 0;
  for (int i = 0; i < k; ++i) {
    auto const cur_idx = cur + i;
    if (cur_idx >= std::size(arr)) break;
    cur_max = std::max(cur_max, arr[cur_idx]);
    res = std::max(res, cur_max * (i + 1) + max_sum(cur_idx + 1, arr, k, dp));
  }
  return dp[cur] = res;
}

class Solution {
 public:
  int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
    auto const n = std::size(arr);
    std::vector<int> dp(n, -1);
    return max_sum(0, arr, k, dp);
  }
};
