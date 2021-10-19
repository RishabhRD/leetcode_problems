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

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    constexpr static int inf = 1e6;
    const int n = size(coins);
    vector dp(amount + 1, vector(n + 1, inf));
    for (int i = 0; i <= n; i++) { dp[0][i] = 0; }
    for (int i = 1; i <= amount; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = dp[i][j - 1];
        if (i - coins[j - 1] >= 0) {
          dp[i][j] = min(dp[i][j], 1 + dp[i - coins[j - 1]][j]);
        }
      }
    }
    return dp[amount][n] >= inf ? -1 : dp[amount][n];
  }
};
