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
  int maxProductPath(std::vector<std::vector<int>>& grid) {
    constexpr static int mod = 1e9 + 7;
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);

    std::vector min(m, std::vector(n, 0ll));
    std::vector max(m, std::vector(n, 0ll));

    min[0][0] = grid[0][0];
    max[0][0] = grid[0][0];

    for (int i = 1; i < m; ++i) {
      min[i][0] = min[i - 1][0] * grid[i][0];
      max[i][0] = max[i - 1][0] * grid[i][0];
    }

    for (int j = 1; j < n; ++j) {
      min[0][j] = min[0][j - 1] * grid[0][j];
      max[0][j] = max[0][j - 1] * grid[0][j];
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (grid[i][j] < 0) {
          max[i][j] = std::min(min[i - 1][j], min[i][j - 1]) * grid[i][j];
          min[i][j] = std::max(max[i - 1][j], max[i][j - 1]) * grid[i][j];
        } else {
          min[i][j] = std::min(min[i - 1][j], min[i][j - 1]) * grid[i][j];
          max[i][j] = std::max(max[i - 1][j], max[i][j - 1]) * grid[i][j];
        }
      }
    }
    if (max[m - 1][n - 1] < 0) return -1;
    return max[m - 1][n - 1] % mod;
  }
};
