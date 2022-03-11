#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
  bool canPartition(vector<int> &nums) {
    int const sum = accumulate(begin(nums), end(nums), 0);
    if (sum % 2 != 0) return false;
    int const n = size(nums);
    int const target = sum / 2;
    vector dp(target + 1, false);
    dp[0] = true;
    for (int num : nums) {
      for (int j = target; j >= 0; j--) {
        if (j - num >= 0) dp[j] = dp[j] || dp[j - num];
      }
    }
    return dp[target];
  }
};
