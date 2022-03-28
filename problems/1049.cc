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
    vector dp(k + 1, false);
    dp[0] = true;
    for (int n : stones) {
      for (int j = k; j >= 0; j--) {
        if (j - n >= 0) { dp[j] = dp[j] or dp[j - n]; }
        if (dp[j]) { s2 = max(s2, j); }
      }
    }
    return sum - 2 * s2;
  }
};
