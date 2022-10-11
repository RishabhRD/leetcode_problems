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

void dfs(std::vector<std::vector<int>>& grid, int i, int j) {
  if (grid[i][j] == 1) return;
  grid[i][j] = 1;
  constexpr static std::array<int, 4> incr_x = {-1, 1, 0, 0};
  constexpr static std::array<int, 4> incr_y = {0, 0, -1, 1};
  for (int k = 0; k < 4; ++k) {
    auto const new_x = i + incr_x[k];
    auto const new_y = j + incr_y[k];
    if (new_x >= 0 and new_y >= 0 and new_x < std::size(grid) and
        new_y < std::size(grid[0])) {
      dfs(grid, new_x, new_y);
    }
  }
}

class Solution {
 public:
  int closedIsland(std::vector<std::vector<int>>& grid) {
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    for (int i = 0; i < m; ++i) {
      dfs(grid, i, 0);
      dfs(grid, i, n - 1);
    }
    for (int j = 0; j < n; ++j) {
      dfs(grid, 0, j);
      dfs(grid, m - 1, j);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          ++ans;
          dfs(grid, i, j);
        }
      }
    }
    return ans;
  }
};
