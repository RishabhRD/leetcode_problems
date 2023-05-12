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

using ll = long long;

ll dfs(ll i, ll j, std::vector<std::vector<int>> const& matrix,
       std::vector<std::vector<ll>>& dp) {
  if (dp[i][j] != -1) return dp[i][j];
  ll max = 1;
  if (i > 0 && matrix[i][j] < matrix[i - 1][j])
    max = std::max(max, 1 + dfs(i - 1, j, matrix, dp));
  if (j > 0 && matrix[i][j] < matrix[i][j - 1])
    max = std::max(max, 1 + dfs(i, j - 1, matrix, dp));
  if (i < matrix.size() - 1 && matrix[i][j] < matrix[i + 1][j])
    max = std::max(max, 1 + dfs(i + 1, j, matrix, dp));
  if (j < matrix[0].size() - 1 && matrix[i][j] < matrix[i][j + 1])
    max = std::max(max, 1 + dfs(i, j + 1, matrix, dp));
  return dp[i][j] = max;
}

class Solution {
 public:
  int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
    ll const m = matrix.size();
    ll const n = matrix[0].size();

    std::vector dp(m, std::vector(n, -1ll));
    ll max = 0;
    for (ll i = 0; i < m; ++i) {
      for (ll j = 0; j < n; ++j) {
        max = std::max(max, dfs(i, j, matrix, dp));
      }
    }
    return max;
  }
};
