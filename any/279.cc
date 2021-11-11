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
  int numSquares(int n) {
    vector dp(n + 1, n + 1);
    dp[0] = 0;
    const int k = sqrt(n);
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= n; j++) {
        if (j - i * i >= 0) dp[j] = min(dp[j], 1 + dp[j - i * i]);
      }
    }
    return dp[n];
  }
};
