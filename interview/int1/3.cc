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

void dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int x , int y){
  visited[x][y] = true;
  int move_x[] = {-1, 0, 0, 1};
  int move_y[] = {0, -1, 1, 0};
  for(int i = 0; i < 4; i++){
    int new_x = x + move_x[i];
    int new_y = y + move_y[i];
    if(new_x >= 0 and new_y >= 0 and new_x < visited.size() and new_y < visited[0].size()){
      if(grid[new_x][new_y] == '1'){
        if(not visited[new_x][new_y])
          dfs(grid, visited, new_x, new_y);
      }
    }
  }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      const int m = grid.size();
      const int n = grid[0].size();
      vector visited(m, vector<bool>(n));
      int cnt = 0;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n ; j++){
          if(not visited[i][j]){
            if(grid[i][j] == '1'){
              cnt++;
              dfs(grid, visited, i, j);
            }
          }
        }
      }
      return cnt;
    }
};

int main(){
  Solution sol;
  vector<vector<char>> grid = {
    {'1', '1', '1', '1', '0'},
    {'1', '1', '0', '1', '0'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '0', '0', '0'}
  };
  cout << sol.numIslands(grid) << endl;
}
