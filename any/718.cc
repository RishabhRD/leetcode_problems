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
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int m = size(nums1);
    int n = size(nums2);
    vector<int> dp(n + 1);
    int ans = 0;
    for(int i = m - 1; i >= 0; i--){
      for(int j = 0; j < n; j++){
        dp[j] = nums1[i] == nums2[j] ? (1 + dp[j + 1]) : 0;
        ans = max(ans, dp[j]);
      }
    }
    return ans;
  }
};
