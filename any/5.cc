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
    string longestPalindrome(string s) {
      const auto n = size(s);
      string_view str = s;
      vector dp(n, vector(n, false));
      string_view substr;
      for(size_t i = 0; i < n; i++){
        dp[i][i] = true;
        substr = str.substr(i, 1);
      }
      for(size_t i = 0; i < n - 1; i++){
        dp[i][i + 1] = s[i] == s[i + 1] ? true : false;
        if(dp[i][i + 1]){
          substr = str.substr(i, 2);
        }
      }
      for(size_t len = 3; len <= n; len++){
        for(size_t i = 0; i <= n - len; i++){
          size_t j = i + len - 1;
          dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : false;
          if(dp[i][j]){
            substr = str.substr(i, j - i + 1);
          }
        }
      }
      return string(substr);
    }
};
