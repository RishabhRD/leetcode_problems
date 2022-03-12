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

class Solution {
public:
  bool isMatch(string s, string p) {
    int const m = size(s);
    int const n = size(p);
    vector dp(m + 1, vector(n + 1, false));
    dp[0][0] = true;
    for (int j = 2; j <= n; j++) {
      if (p[j - 1] != '*')
        dp[0][j] = false;
      else
        dp[0][j] = dp[0][j - 2];
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == p[j - 1] or p[j - 1] == '.') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          if (p[j - 2] == '.' or p[j - 2] == s[i - 1]) {
            dp[i][j] = dp[i][j - 2] or dp[i - 1][j];
          } else {
            dp[i][j] = dp[i][j - 2];
          }
        }
      }
    }
    return dp[m][n];
  }
};
