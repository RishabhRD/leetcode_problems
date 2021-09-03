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

int fast_find(vector<int>& prices){
  int max_cur = 0;
  int max_so_far = 0;
  for(int i = 1; i < size(prices); i++){
    max_cur = max(0, max_cur += prices[i] - prices[i - 1]);
    max_so_far = max(max_so_far, max_cur);
  }
  return max_so_far;
}

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    const int n = size(prices);
    if (n == 0 or n == 1) return 0;
    if(k > n / 2){
      return fast_find(prices);
    }
    vector<vector<int>> dp(k + 1, vector<int>(n));
    for (int i = 1; i <= k; i++) {
      int max_till_last_trasaction = -prices[0];
      for (int j = 1; j < n; j++) {
        dp[i][j] = max(dp[i][j - 1], prices[j] + max_till_last_trasaction);
        max_till_last_trasaction = max(max_till_last_trasaction,
          dp[i - 1][j - 1] - prices[j]);
      }
    }
    return dp[k][n - 1];
  }
};
