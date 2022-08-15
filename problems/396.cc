#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename Iterator>
int idx_weight_sum_range(Iterator begin, Iterator end) {
  auto const n = std::distance(begin, end);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += (i * (*begin));
    ++begin;
  }
  return sum;
}

class Solution {
 public:
  int maxRotateFunction(std::vector<int>& nums) {
    auto const n = std::size(nums);
    std::vector<int> dp(n, 0);
    dp[0] = idx_weight_sum_range(std::cbegin(nums), std::cend(nums));
    auto const sum = std::accumulate(std::cbegin(nums), std::cend(nums), 0);
    for (int i = 1; i < n; ++i) {
      dp[i] = dp[i - 1] - sum + n * nums[i - 1];
    }
    return *std::max_element(std::cbegin(dp), std::cend(dp));
  }
};
