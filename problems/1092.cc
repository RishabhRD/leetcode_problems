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

auto find_lcs(const string &str1, const string &str2) {
  const int m = size(str1);
  const int n = size(str2);
  vector dp(m + 1, vector(n + 1, ""s));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
      } else {
        if (size(dp[i - 1][j]) > size(dp[i][j - 1]))
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i][j - 1];
      }
    }
  }
  return dp[m][n];
}

class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    string res = "";
    int i = 0;
    int j = 0;
    for (auto c : find_lcs(str1, str2)) {
      while (str1[i] != c) res += str1[i++];
      while (str2[j] != c) res += str2[j++];
      res += c;
      i++;
      j++;
    }
    res += str1.substr(i);
    res += str2.substr(j);
    return res;
  }
};
