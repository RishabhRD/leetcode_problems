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
constexpr ll mod = 1e9 + 7;

ll dfs(std::vector<std::vector<int>> const& grid, ll i, ll j,
       std::vector<std::vector<ll>>& dp) {
  if (dp[i][j] != -1) return dp[i][j];
  constexpr static int dx[] = {-1, 0, 0, 1};
  constexpr static int dy[] = {0, -1, 1, 0};
  ll ans = 1;
  for (int k = 0; k < 4; ++k) {
    auto const x = i + dx[k];
    auto const y = j + dy[k];
    if (x >= 0 and y >= 0 and x < std::size(grid) and y < std::size(grid[0]) and
        grid[x][y] > grid[i][j]) {
      ans = (ans + dfs(grid, x, y, dp)) % mod;
    }
  }
  return dp[i][j] = ans;
}

class Solution {
 public:
  int countPaths(std::vector<std::vector<int>>& grid) {
    ll const m = std::size(grid);
    ll const n = std::size(grid[0]);
    ll ans = 0;
    std::vector dp(m, std::vector(n, -1ll));
    for (ll i = 0; i < m; ++i) {
      for (ll j = 0; j < n; ++j) {
        ans = (ans + dfs(grid, i, j, dp)) % mod;
      }
    }
    return ans;
  }
};
