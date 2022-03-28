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
  int integerBreak(int n) {
    vector dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
      }
    }
    return dp[n];
  }
};
