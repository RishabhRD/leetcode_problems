#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    auto sum = accumulate(cbegin(nums), cend(nums), 0);
    if(sum % 2) return false;
    auto target = sum / 2;
    const int n = size(nums);
    vector dp(target + 1, false);
    dp[0] = true;
    for(const int num : nums){
      for(int j = target; j >= 0; j--){
        if(j - num >= 0){
          dp[j] = dp[j] or dp[j - num];
        }
      }
    }
    return dp[target];
  }
};
