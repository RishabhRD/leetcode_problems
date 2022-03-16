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

int double_dfs(int x,
  int y1,
  int y2,
  vector<vector<int>> &grid,
  vector<vector<vector<int>>> &dp) {
  if (y1 >= size(grid[0]) or y2 >= size(grid[0])) return 0;
  if (x >= size(grid)) { return 0; }
  if (dp[x][y1][y2] != -1) return dp[x][y1][y2];
  int const y1_score = grid[x][y1];
  int const y2_score = grid[x][y2];
  int score{};
  if (y1 == y2) {
    grid[x][y1] -= y1_score;
    score = y1_score;
  } else {
    grid[x][y1] -= y1_score;
    grid[x][y2] -= y2_score;
    score = y1_score + y2_score;
  }
  int max_score = 0;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      max_score = max(max_score, double_dfs(x + 1, y1 + i, y2 + j, grid, dp));
    }
  }
  if (y1 == y2) {
    grid[x][y1] += y1_score;
  } else {
    grid[x][y1] += y1_score;
    grid[x][y2] += y2_score;
  }
  return dp[x][y1][y2] = score + max_score;
}

class Solution {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    int const n = size(grid);
    int const m = size(grid[0]);
    vector dp(n, vector(m, vector(m, -1)));
    return double_dfs(0, 0, m - 1, grid, dp);
  }
};
