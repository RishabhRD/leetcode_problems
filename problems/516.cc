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
  int longestPalindromeSubseq(string s) {
    const int n = size(s);
    vector dp(n + 1, vector(n + 1, 0));
    for(int i = n - 1; i >= 0; i--){
      dp[i][i] = 1;
      for(int j = i + 1; j < n; j++){
        if(s[i] == s[j])
          dp[i][j] = 2 + dp[i + 1][j - 1];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
    }
    return dp[0][n - 1];
  }
};
