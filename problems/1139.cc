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

auto make_left_grid(std::vector<std::vector<int>> const &grid) {
  auto const m = std::size(grid);
  auto const n = std::size(grid[0]);
  std::vector left_grid(m, std::vector(n, 0));
  for (int i = 0; i < m; ++i) {
    int cur = 0;
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        ++cur;
      } else {
        cur = 0;
      }
      left_grid[i][j] = cur;
    }
  }
  return left_grid;
}

auto make_up_grid(std::vector<std::vector<int>> const &grid) {
  auto const m = std::size(grid);
  auto const n = std::size(grid[0]);
  std::vector up_grid(m, std::vector(n, 0));
  for (int j = 0; j < n; ++j) {
    int cur = 0;
    for (int i = 0; i < m; ++i) {
      if (grid[i][j] == 1) {
        ++cur;
      } else {
        cur = 0;
      }
      up_grid[i][j] = cur;
    }
  }
  return up_grid;
}

class Solution {
public:
  int largest1BorderedSquare(std::vector<std::vector<int>> &grid) {
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);

    auto const left_grid = make_left_grid(grid);
    auto const up_grid = make_up_grid(grid);
    auto ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        auto const max_dist = std::min(left_grid[i][j], up_grid[i][j]);
        for (int cur_dist = 1; cur_dist <= max_dist; ++cur_dist) {
          if (up_grid[i][j - cur_dist + 1] >= cur_dist and
              left_grid[i - cur_dist + 1][j] >= cur_dist) {
            ans = std::max(ans, cur_dist * cur_dist);
          }
        }
      }
    }
    return ans;
  }
};
