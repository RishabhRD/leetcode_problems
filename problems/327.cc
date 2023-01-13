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

using ll = long long;

// -2 1 0 4 1 8

ll merge(std::vector<ll>& nums, ll low, ll mid, ll high, ll lower, ll upper) {
  ll k = mid + 1;
  ll j = mid + 1;
  ll count = 0;
  for (ll i = low; i <= mid; ++i) {
    while (k <= high && nums[k] - nums[i] < lower) {
      ++k;
    }
    while (j <= high && nums[j] - nums[i] <= upper) {
      ++j;
    }
    count += j - k;
  }
  std::sort(std::begin(nums) + low, std::begin(nums) + high + 1);
  return count;
}

ll count_range(std::vector<ll>& nums, ll low, ll high, ll lower, ll upper) {
  if (high == low) {
    if (nums[low] >= lower && nums[low] <= upper) {
      return 1;
    } else {
      return 0;
    }
  } else if (high < low)
    return 0;
  auto const mid = (low + high) / 2;
  auto const left_sum = count_range(nums, low, mid, lower, upper);
  auto const right_sum = count_range(nums, mid + 1, high, lower, upper);
  auto const mid_sum = merge(nums, low, mid, high, lower, upper);
  return left_sum + right_sum + mid_sum;
}

class Solution {
 public:
  int countRangeSum(std::vector<int>& nums, int lower, int upper) {
    ll const n = nums.size();
    std::vector<ll> sums{std::begin(nums), std::end(nums)};
    for (ll i = 1; i < n; ++i) {
      sums[i] = nums[i] + sums[i - 1];
    }
    return count_range(sums, 0, n - 1, lower, upper);
  }
};
