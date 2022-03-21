#include <optional>
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

int dfs(int x,
  int y,
  vector<vector<int>> const &matrix,
  vector<vector<optional<int>>> &dp) {
  if (x == size(matrix) - 1) return matrix[x][y];
  if (dp[x][y].has_value()) return dp[x][y].value();
  constexpr static array dys = { -1, 0, 1 };
  int res = INT32_MAX;
  for (auto const dy : dys) {
    int const new_y = y + dy;
    if (new_y >= 0 and new_y < size(matrix[0]))
      res = min(res, dfs(x + 1, new_y, matrix, dp));
  }
  dp[x][y] = res + matrix[x][y];
  return dp[x][y].value();
}

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int const m = size(matrix);
    int const n = size(matrix[0]);
    vector dp(m, vector(n, optional<int>{ nullopt }));
    int res = INT32_MAX;
    for (int j = 0; j < n; j++) { res = min(res, dfs(0, j, matrix, dp)); }
    return res;
  }
};
