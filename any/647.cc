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
  int countSubstrings(string s) {
    const int n = size(s);
    vector dp(n, vector(n, false));
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
      for(int j = i; j < n; j++){
        if(i == j){
          dp[i][j] = true;
        }else if(i + 1 == j){
          if(s[i] == s[j]){
            dp[i][j] = true;
          }
        }else{
          if(s[i] == s[j])
            dp[i][j] = dp[i + 1][j - 1];
        }
        if(dp[i][j])
          cnt++;
      }
    }
    return cnt;
  }
};
