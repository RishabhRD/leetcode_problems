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

class Solution {
 public:
  bool isPossibleToCutPath(std::vector<std::vector<int>>& grid) {
    ll const m = grid.size();
    ll const n = grid[0].size();
    std::vector to_reach_end(m, std::vector(n, 0ll));
    std::vector to_reach(m, std::vector(n, 0ll));
    to_reach[0][0] = 1;
    for (ll i = 1; i < m; ++i) {
      if (grid[i][0] == 1) to_reach[i][0] += to_reach[i - 1][0];
    }
    for (ll j = 1; j < n; ++j) {
      if (grid[0][j] == 1) {
        to_reach[0][j] += to_reach[0][j - 1];
      }
    }
    to_reach_end[m - 1][n - 1] = 1;
    for (ll i = m - 2; i >= 0; --i) {
      if (grid[i][n - 1] == 1)
        to_reach_end[i][n - 1] += to_reach_end[i + 1][n - 1];
    }
    for (ll j = n - 2; j >= 0; --j) {
      if (grid[m - 1][j] == 1) {
        to_reach_end[m - 1][j] += to_reach_end[m - 1][j + 1];
      }
    }
    for (ll i = 1; i < m; ++i) {
      for (ll j = 1; j < n; ++j) {
        if (grid[i][j] != 0) {
          to_reach[i][j] = (to_reach[i - 1][j] + to_reach[i][j - 1]) % mod;
        }
      }
    }
    for (ll i = m - 2; i >= 0; --i) {
      for (ll j = n - 2; j >= 0; --j) {
        if (grid[i][j] != 0) {
          to_reach_end[i][j] =
              (to_reach_end[i + 1][j] + to_reach_end[i][j + 1]) % mod;
        }
      }
    }
    ll const total_init_path = to_reach_end[0][0];
    for (ll i = 0; i < m; ++i) {
      for (ll j = 0; j < n; ++j) {
        if (i == 0 && j == 0) continue;
        if (i == m - 1 && j == n - 1) continue;
        ll const to_reach_cur = to_reach[i][j];
        ll const to_reach_last = to_reach_end[i][j];
        if (total_init_path == (to_reach_cur * to_reach_last) % mod)
          return true;
      }
    }
    return false;
  }
};
