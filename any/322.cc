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
  int coinChange(vector<int> &coins, int amount) {
    const int n = size(coins);
    vector dp(amount + 1, amount + 1);
    dp[0] = 0;
    for(int coin : coins){
      for(int j = 1; j <= amount; j++){
        if(j - coin >= 0)
          dp[j] = min(dp[j], 1 + dp[j - coin]);
      }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};
