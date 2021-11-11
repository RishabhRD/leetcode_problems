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
    const int m = size(nums1);
    const int n = size(nums2);
    vector dp(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = n; j >= 1; j--) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[j] = 1 + dp[j - 1];
        } else {
          dp[j] = 0;
        }
        ans = max(ans, dp[j]);
      }
    }
    return ans;
  }
};
