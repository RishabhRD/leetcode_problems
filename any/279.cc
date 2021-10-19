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

int num_squares(int n, vector<int>& dp){
  if(n <= 0) return 0;
  if(n == 1) return 1;
  if(dp[n] != -1) return dp[n];
  int count = INT32_MAX;
  for(int i = 1; i <= n; i++){
    int num = i * i;
    if(num > n) break;
    count = min(count, 1 + num_squares(n - num, dp));
  }
  return dp[n] = count;
}

class Solution {
public:
    int numSquares(int n) {
      vector<int> dp(n + 1, -1);
      return num_squares(n, dp);
    }
};
