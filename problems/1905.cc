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

bool dfs(std::vector<std::vector<int>> const& grid1,
         std::vector<std::vector<int>>& grid2, int i, int j) {
  grid2[i][j] = 0;
  constexpr static int dx[] = {0, 0, -1, 1};
  constexpr static int dy[] = {-1, 1, 0, 0};
  bool ans = true;
  if (grid1[i][j] == 0) ans = false;
  for (int k = 0; k < 4; ++k) {
    auto const new_x = i + dx[k];
    auto const new_y = j + dy[k];

    if (new_x >= 0 and new_y >= 0 and new_x < std::size(grid1) and
        new_y < std::size(grid1[0])) {
      if (grid2[new_x][new_y] == 0) continue;
      if (!dfs(grid1, grid2, new_x, new_y)) {
        ans = false;
      }
    }
  }
  return ans;
}

class Solution {
 public:
  int countSubIslands(std::vector<std::vector<int>>& grid1,
                      std::vector<std::vector<int>>& grid2) {
    auto const m = std::size(grid1);
    auto const n = std::size(grid1[0]);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid2[i][j] == 0) continue;
        if (dfs(grid1, grid2, i, j)) ++ans;
      }
    }
    return ans;
  }
};
