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

int dfs(vector<vector<int>> const &matrix,
  vector<vector<int>> &cache,
  int i,
  int j) {
  if (cache[i][j] != -1) return cache[i][j];
  auto max_path_sum = 0;
  pair<int, int> d[] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
  for (auto [dx, dy] : d) {
    auto const x = i + dx;
    auto const y = j + dy;
    if (x >= 0 and y >= 0 and x < size(matrix) and y < size(matrix[0])
        and matrix[x][y] > matrix[i][j]) {
      max_path_sum = max(max_path_sum, dfs(matrix, cache, x, y));
    }
  }
  return cache[i][j] = 1 + max_path_sum;
}

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int const m = size(matrix);
    int const n = size(matrix[0]);
    vector dp(m, vector(n, -1));
    int max_path_sum = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        max_path_sum = max(max_path_sum, dfs(matrix, dp, i, j));
      }
    }
    return max_path_sum;
  }
};
