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
  int minDistance(string word1, string word2) {
    const int m = size(word1);
    const int n = size(word2);
    vector dp(m + 1, vector(n + 1, 0));
    for(int i = 1; i <= n; i++){
      dp[0][i] = i;
    }
    for(int i = 1; i <= m; i++){
      dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else {
          dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};

