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

int dfs(vector<vector<int>> &matrix,
  int cur_x,
  int cur_y,
  vector<vector<int>> &dp) {
  if (dp[cur_x][cur_y] >= 0) return dp[cur_x][cur_y];
  constexpr pair<int, int> incr[] = {
    { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 }
  };
  int path = 1;
  for (auto [incr_x, incr_y] : incr) {
    const int new_x = cur_x + incr_x;
    const int new_y = cur_y + incr_y;
    if (new_x >= 0 and new_y >= 0 and new_x < size(matrix)
        and new_y < size(matrix[0])
        and matrix[cur_x][cur_y] < matrix[new_x][new_y]) {
      path = max(path, 1 + dfs(matrix, new_x, new_y, dp));
    }
  }
  return dp[cur_x][cur_y] = path;
}

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    vector dp(size(matrix), vector<int>(size(matrix[0]), -1));
    const int m = size(matrix);
    const int n = size(matrix[0]);
    int max_path = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        max_path = max(max_path, dfs(matrix, i, j, dp));
      }
    }
    return max_path;
  }
};
