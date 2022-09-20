#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int constrainedSubsetSum(std::vector<int>& nums, int k) {
    auto const n = std::size(nums);
    std::vector<int> dp(n);
    std::deque<int> dq;

    int low = 0;
    for (int high = 0; high < n; ++high) {
      auto dq_max = 0;
      if (not empty(dq)) {
        dq_max = dp[dq.front()];
      }
      dp[high] = std::max(nums[high], nums[high] + dq_max);

      while (not std::empty(dq) and dp[dq.back()] < dp[high]) {
        dq.pop_back();
      }
      dq.push_back(high);
      while (high - low + 1 > k) {
        if (!dq.empty() and dq.front() == low) dq.pop_front();
        ++low;
      }
    }
    return *std::max_element(std::cbegin(dp), std::cend(dp));
  }
};
