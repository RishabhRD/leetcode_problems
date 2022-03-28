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
  int minInsertions(string s) {
    const int n = size(s);
    vector dp(n + 1, vector(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == s[n - j + 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return n - dp[n][n];
  }
};
