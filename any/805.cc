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

bool check_subset_sum(vector<double> const &nums) {
  int sum = 0;
  int const n = size(nums);
  vector dp(sum + 1, nums[0] == false);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      if (j - nums[i - 1] >= 0) dp[j] = dp[j - nums[i - 1]];
    }
  }
  return dp[sum];
}

class Solution {
public:
  bool splitArraySameAverage(vector<int> &nums) {
    auto const n = size(nums);
    auto const sum = accumulate(begin(nums), end(nums), 0);
    double const avg = static_cast<double>(sum) / n;
    vector<double> vec{ begin(nums), end(nums) };
    for (auto &num : vec) num -= avg;
    return check_subset_sum(vec);
  }
};
