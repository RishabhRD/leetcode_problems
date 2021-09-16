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

void dfs(const vector<vector<char>> &grid,
  vector<vector<bool>> &visited,
  int i,
  int j) {
  constexpr static pair<int, int> dir[] = {
    { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
  };
  visited[i][j] = true;
  for (const auto [incr_x, incr_y] : dir) {
    const int new_x = i + incr_x;
    const int new_y = j + incr_y;
    if (new_x >= 0 and new_y >= 0 and new_x < size(grid)
        and new_y < size(grid[0]) and not visited[new_x][new_y]
        and grid[new_x][new_y] == '1') {
      dfs(grid, visited, new_x, new_y);
    }
  }
}

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    vector visited(size(grid), vector<bool>(size(grid[0])));
    int cnt = 0;
    for(int i = 0; i < size(grid); i++){
      for(int j = 0; j < size(grid[0]); j++){
        if(not visited[i][j] and grid[i][j] == '1'){
          cnt++;
          dfs(grid, visited, i, j);
        }
      }
    }
    return cnt;
  }
};
