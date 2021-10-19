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
    int rob(vector<int>& nums) {
      const int n = size(nums);
      vector<int> dp(n);
      int max_ele = 0;
      for(int i = 0; i < n; i++){
        dp[i] = nums[i];
        for(int j = i - 2; j >= 0; j--){
          dp[i] = max(dp[i], nums[i] + dp[j]);
        }
        max_ele = max(max_ele, dp[i]);
      }
      return max_ele;
    }
};
