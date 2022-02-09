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
  string longestPalindrome(string given_str) {
    string_view s = given_str;
    int const n = size(s);
    vector dp(n, vector(n, false));
    auto palin_substr = s.substr(0, 1);
    for (int i = 0; i < n; i++) { dp[i][i] = true; }
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        palin_substr = s.substr(i, 2);
      }
    }
    for (int len = 3; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int const j = i + len - 1;
        dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1];
        if (dp[i][j]) palin_substr = s.substr(i, len);
      }
    }
    return string(palin_substr);
  }
};
