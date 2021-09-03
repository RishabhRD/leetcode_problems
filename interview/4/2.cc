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
  int maxProfit(vector<int> &prices) {
    const int k = 2;
    const int n = size(prices);
    if (n == 0 or n == 1) return 0;
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

int main(){
  Solution sol;
  vector<int> prices = {3,3,5,0,0,3,1,4};
  cout << sol.maxProfit(prices) << endl;
}
