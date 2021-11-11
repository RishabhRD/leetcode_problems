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
  int change(int amount, vector<int> &coins) {
    const int n = size(coins);
    vector dp(amount + 1, 0);
    dp[0] = 1;
    for(int coin : coins){
      for(int j = 1; j <= amount; j++){
        if(j - coin >= 0){
          dp[j] += dp[j - coin];
        }
      }
    }
    return dp[amount];
  }
};
