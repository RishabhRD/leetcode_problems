#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

void dfs(vector<vector<char>> const &grid,
  int i,
  int j,
  vector<vector<bool>> &visited) {
  if (i < 0 or j < 0 or i >= size(grid) or j >= size(grid[0]) or visited[i][j]
      or grid[i][j] == '0') {
    return;
  }
  visited[i][j] = true;
  dfs(grid, i + 1, j, visited);
  dfs(grid, i, j + 1, visited);
  dfs(grid, i - 1, j, visited);
  dfs(grid, i, j - 1, visited);
}

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int const m = size(grid);
    int const n = size(grid[0]);
    int cnt{ 0 };
    vector visited(m, vector(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1' and not visited[i][j]) {
          dfs(grid, i, j, visited);
          cnt++;
        }
      }
    }
    return cnt;
  }
};
