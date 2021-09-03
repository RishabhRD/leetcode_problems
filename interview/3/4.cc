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

int dfs(int x, int y, const vector<vector<int>>& matrix, vector<vector<int>>& cache){
  if(cache[x][y] != 0){
    return cache[x][y];
  }
  constexpr static int dir[4][2] {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
  };
  int max_res = 1;
  for(int i = 0; i < 4; i++){
    const int new_x = x + dir[i][0];
    const int new_y = y + dir[i][1];
    if(new_x >= 0 and new_y >= 0 and new_x < matrix.size() and new_y < matrix[0].size()){
      if(matrix[new_x][new_y] > matrix[x][y]){
        max_res = max(max_res, 1 + dfs(new_x, new_y, matrix, cache));
      }
    }
  }
  cache[x][y] = max_res;
  return max_res;
}

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    const int m = size(matrix);
    const int n = size(matrix[0]);
    vector<vector<int>> cache(m, vector<int>(n));
    int max_res = 1;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        max_res = max(max_res, dfs(i, j, matrix, cache));
      }
    }
    return max_res;
  }
};
