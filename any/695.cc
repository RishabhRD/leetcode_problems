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

int largest_area(vector<vector<int>> const &grid,
  int cur_x,
  int cur_y,
  vector<vector<bool>> &visited) {
  if (cur_x < 0 or cur_y < 0 or cur_x >= size(grid) or cur_y >= size(grid[0]))
    return 0;
  if (grid[cur_x][cur_y] == 0) return 0;
  if (visited[cur_x][cur_y]) return 0;
  visited[cur_x][cur_y] = true;
  constexpr static pair<int, int> d[] = {
    { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 }
  };
  int area = 1;
  for (auto [dx, dy] : d) {
    area += largest_area(grid, cur_x + dx, cur_y + dy, visited);
  }
  return area;
}

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    const int m = size(grid);
    const int n = size(grid[0]);
    vector visited(m, vector(n, false));
    int max_area = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (not visited[i][j]) {
          max_area = max(max_area, largest_area(grid, i, j, visited));
        }
      }
    }
    return max_area;
  }
};
