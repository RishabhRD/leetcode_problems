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

class sliding_window {
  std::deque<int> dq;
  std::vector<int> const& nums;
  int k;
  int low;
  int high;

 public:
  sliding_window(std::vector<int> const& nums, int k)
      : nums(nums), k(k), low(0), high(0) {}

  void push() {
    while (not std::empty(dq) and nums[dq.back()] < nums[high]) {
      dq.pop_back();
    }
    dq.push_back(high);
    while (high - low + 1 > k) {
      if (dq.front() == low) dq.pop_front();
      ++low;
    }
    ++high;
  }

  int maximum() {
    if (dq.empty())
      return 0;
    else
      return nums[dq.front()];
  }
};

class Solution {
 public:
  int maxResult(std::vector<int>& nums, int k) {
    auto const n = std::size(nums);
    std::vector dp(n, 0);

    sliding_window sl(dp, k);
    for (int i = 0; i < n; ++i) {
      dp[i] = nums[i] + sl.maximum();
      sl.push();
    }
    return dp[n - 1];
  }
};
