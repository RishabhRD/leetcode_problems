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

template <typename Predicate>
ll binary_search(ll low, ll high, Predicate&& predicate) {
  if (low >= high) return low;
  auto const mid = low + (high - low) / 2;
  if (predicate(mid)) {
    return binary_search(mid + 1, high, predicate);
  } else {
    return binary_search(low, mid, predicate);
  }
}

class Solution {
 public:
  long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
    ll const n = nums.size();
    std::sort(std::begin(nums), std::end(nums));
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
      auto const cur_low = lower - nums[i];
      auto const cur_high = upper - nums[i];
      auto const low_start =
          binary_search(i + 1, n, [&](auto i) { return nums[i] < cur_low; });
      auto const high_end =
          binary_search(i + 1, n, [&](auto i) { return nums[i] <= cur_high; });
      sum += (high_end - low_start);
    }
    return sum;
  }
};
