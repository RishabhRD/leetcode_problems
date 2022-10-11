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

bool has_cycle(std::vector<std::vector<char>> const& grid, int x, int y,
               int last_x, int last_y,
               std::vector<std::vector<bool>>& visited) {
  visited[x][y] = true;
  constexpr static int dx[] = {0, 0, -1, 1};
  constexpr static int dy[] = {-1, 1, 0, 0};
  for (int k = 0; k < 4; ++k) {
    auto const new_x = x + dx[k];
    auto const new_y = y + dy[k];

    if (new_x >= 0 and new_y >= 0 and new_x < std::size(grid) and
        new_y < std::size(grid[0])) {
      if (new_x == last_x and new_y == last_y) continue;
      if (grid[new_x][new_y] != grid[x][y]) continue;
      if (visited[new_x][new_y] ||
          has_cycle(grid, new_x, new_y, x, y, visited)) {
        return true;
      }
    }
  }
  return false;
}

struct Solution {
  bool containsCycle(std::vector<std::vector<char>>& grid) {
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    std::vector visited(m, std::vector(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (not visited[i][j] and has_cycle(grid, i, j, -1, -1, visited)) {
          return true;
        }
      }
    }
    return false;
  }
};
