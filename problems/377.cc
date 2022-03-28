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
  int combinationSum4(vector<int> &nums, int target) {
    const int n = size(nums);
    vector dp(target + 1, 0u);
    dp[0] = 1;
    for (int j = 1; j <= target; j++)
      for (int num : nums)
        if (j - num >= 0) dp[j] += dp[j - num];
    return dp[target];
  }
};
