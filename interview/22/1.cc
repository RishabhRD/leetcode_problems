#include <queue>
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
  int lastStoneWeightII(vector<int> &stones) {
    const int sum = accumulate(cbegin(stones), cend(stones), 0);
    const int k = sum / 2;
    const int n = size(stones);
    int s2 = 0;
    vector dp(k + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) { dp[0][i] = true; }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        if(dp[j][i - 1] or (j >= stones[i - 1] and dp[j - stones[i - 1]][i - 1])){
          dp[j][i] = true;
          s2 = max(s2, j);
        }
      }
    }
    return sum - 2 * s2;
  }
};
