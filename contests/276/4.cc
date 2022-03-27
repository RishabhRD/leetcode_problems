#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& piles, int i, int k, vector<vector<int>>& dp) {
  if (k == 0 || i == size(piles)) return 0;
  if (dp[i][k] != -1) return dp[i][k];
  int res = dfs(piles, i + 1, k, dp);
  int sum = 0;
  for (int j = 0; j < size(piles[i]) and k - j > 0; ++j) {
    sum += piles[i][j];
    res = max(res, sum + dfs(piles, i + 1, k - j - 1, dp));
  }
  return dp[i][k] = res;
}

class Solution {
 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int const n = size(piles);
    vector dp(n + 1, vector(k + 1, -1));
    return dfs(piles, 0, k, dp);
  }
};
