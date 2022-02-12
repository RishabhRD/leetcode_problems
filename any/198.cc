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
  int rob(vector<int> &nums) {
    int const n = size(nums);
    int dp0 = 0;
    int dp1 = nums[0];
    for (int i = 2; i <= n; i++) {
      int const new_dp = max(dp1, dp0 + nums[i - 1]);
      dp0 = dp1;
      dp1 = new_dp;
    }
    return dp1;
  }
};
