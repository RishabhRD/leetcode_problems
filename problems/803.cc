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

void dfs(std::vector<std::vector<int>>& grid, int x, int y) {
  if (x >= 0 and x < std::size(grid) and y >= 0 and y < std::size(grid[0]) and
      grid[x][y] == 1) {
    grid[x][y] = 2;
    dfs(grid, x - 1, y);
    dfs(grid, x + 1, y);
    dfs(grid, x, y - 1);
    dfs(grid, x, y + 1);
  }
}

int num_connected(std::vector<std::vector<int>>& grid, int x, int y) {
  if (!(x >= 0 and x < std::size(grid) and y >= 0 and y < std::size(grid[0])))
    return 0;
  if (grid[x][y] == 0 || grid[x][y] == 2) return 0;
  grid[x][y] = 2;
  int ans = 1;
  ans += num_connected(grid, x - 1, y) + num_connected(grid, x + 1, y) +
         num_connected(grid, x, y - 1) + num_connected(grid, x, y + 1);
  return ans;
}

class Solution {
 public:
  std::vector<int> hitBricks(std::vector<std::vector<int>>& grid,
                             std::vector<std::vector<int>>& hits) {
    for (auto const& hit : hits) {
      if (grid[hit[0]][hit[1]] == 1) grid[hit[0]][hit[1]] = -1;
    }

    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    for (int i = 0; i < n; ++i) dfs(grid, 0, i);

    std::vector<int> res;
    for (auto const& hit : hits) {
      res.push_back(num_connected(grid, hit[0], hit[1]));
    }
    return res;
  }
};
