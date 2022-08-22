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

using matrix_t = std::vector<std::vector<int>>;

auto make_top_matrix(matrix_t const& grid) {
  auto const n = std::size(grid);
  matrix_t top = grid;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] != 0) {
        top[i][j] = 1 + top[i - 1][j];
      }
    }
  }
  return top;
}

auto make_bottom_matrix(matrix_t const& grid) {
  auto const n = std::size(grid);
  matrix_t top = grid;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] != 0) {
        top[i][j] = 1 + top[i + 1][j];
      }
    }
  }
  return top;
}

auto make_left_matrix(matrix_t const& grid) {
  auto const n = std::size(grid);
  matrix_t top = grid;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (grid[i][j] != 0) {
        top[i][j] = 1 + top[i][j - 1];
      }
    }
  }
  return top;
}

auto make_right_matrix(matrix_t const& grid) {
  auto const n = std::size(grid);
  matrix_t top = grid;
  for (int i = 0; i < n; ++i) {
    for (int j = n - 2; j >= 0; --j) {
      if (grid[i][j] != 0) {
        top[i][j] = 1 + top[i][j + 1];
      }
    }
  }
  return top;
}

auto make_grid(int n, std::vector<std::vector<int>> const& mines) {
  std::vector grid(n, std::vector(n, 1));
  for (auto const& mine : mines) {
    grid[mine[0]][mine[1]] = 0;
  }
  return grid;
}

class Solution {
 public:
  int orderOfLargestPlusSign(int n, std::vector<std::vector<int>>& mines) {
    auto const grid = make_grid(n, mines);
    auto const top = make_top_matrix(grid);
    auto const left = make_left_matrix(grid);
    auto const right = make_right_matrix(grid);
    auto const bottom = make_bottom_matrix(grid);
    auto ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = std::max(
            ans, std::min({top[i][j], left[i][j], right[i][j], bottom[i][j]}));
      }
    }
    return ans;
  }
};
