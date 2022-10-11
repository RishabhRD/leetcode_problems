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
  int numberOfPaths(std::vector<std::vector<int>>& grid, int k) {
    constexpr static int mod = 1e9 + 7;
    using ll = long long;
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    std::vector dp(m, std::vector(n, std::vector(k, 0ll)));

    {
      // for 0, 0
      auto const idx = grid[0][0] % k;
      dp[0][0][idx] = 1;
    }

    {
      // for 0th columns of each rows
      int cur_sum = grid[0][0];
      for (int i = 1; i < m; ++i) {
        cur_sum += grid[i][0];
        auto const idx = cur_sum % k;
        dp[i][0][idx] = 1;
      }
    }

    {
      // for 0th rows of each columns
      int cur_sum = grid[0][0];
      for (int i = 1; i < n; ++i) {
        cur_sum += grid[0][i];
        auto const idx = cur_sum % k;
        dp[0][i][idx] = 1;
      }
    }

    {
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          auto const offset = grid[i][j] % k;
          auto up = dp[i - 1][j];
          {
            auto rotation_point = std::end(up) - offset;
            if (rotation_point != std::end(up)) {
              std::rotate(std::begin(up), std::end(up) - offset, std::end(up));
            }
          }
          auto left = dp[i][j - 1];
          {
            auto rotation_point = std::end(left) - offset;
            if (rotation_point != std::end(left)) {
              std::rotate(std::begin(left), std::end(left) - offset,
                          std::end(left));
            }
          }

          for (int m = 0; m < k; ++m) {
            dp[i][j][m] = (up[m] + left[m]) % mod;
          }
        }
      }
    }
    return dp[m - 1][n - 1][0];
  }
};
