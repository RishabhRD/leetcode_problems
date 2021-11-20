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
    const int n = size(nums);
    vector<int> dp(n);
    if(n == 1) return nums.back();
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++){
      dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[n - 1];
  }
};
