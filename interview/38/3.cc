#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

int dfs(vector<vector<int>> &grid, int x, int y, int &empty) {
  if (x < 0 or y < 0 or x >= size(grid) or y >= size(grid[0]) or grid[x][y] < 0)
    return 0;
  if (grid[x][y] == 2) {
    if (empty == 0)
      return 1;
    else
      return 0;
  }
  int cnt = 0;
  grid[x][y] = -1;
  empty--;
  cnt += dfs(grid, x + 1, y, empty);
  cnt += dfs(grid, x, y + 1, empty);
  cnt += dfs(grid, x, y - 1, empty);
  cnt += dfs(grid, x - 1, y, empty);
  empty++;
  grid[x][y] = 0;
  return cnt;
}

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    int x, y;
    int empty = 1;
    for (int i = 0; i < size(grid); i++) {
      for (int j = 0; j < size(grid[0]); j++) {
        if (grid[i][j] == 1) {
          x = i;
          y = j;
        } else if (grid[i][j] == 0) {
          empty++;
        }
      }
    }
    return dfs(grid, x, y, empty);
  }
};
