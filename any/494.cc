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
  int findTargetSumWays(vector<int> &nums, int t) {
    const int s = accumulate(cbegin(nums), cend(nums), 0);
    if(s < t or (s + t) % 2) return 0;
    const int k = (s + t) / 2;
    vector dp(k + 1, 0);
    dp[0] = 1;
    const int n = size(nums);
    for(int num : nums){
      for(int j = k; j >= 0; j--){
        if(j - num >= 0){
          dp[j] += dp[j - num];
        }
      }
    }
    return dp[k];
  }
};
