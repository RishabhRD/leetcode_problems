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

auto make_sums(std::vector<int> const& nums, ll low, ll high) {
  ll const n = high - low + 1;
  auto const max = 1 << n;
  std::vector<std::vector<ll>> res(n + 1);
  for (ll i = 0; i < max; ++i) {
    std::bitset<32> bs(i);
    ll sum = 0;
    ll other_sum = 0;
    for (ll j = 0; j < n; ++j) {
      if (bs[j]) {
        sum += nums[low + j];
      } else {
        other_sum += nums[low + j];
      }
    }
    res[bs.count()].push_back(sum - other_sum);
  }
  return res;
}

class Solution {
 public:
  int minimumDifference(std::vector<int>& nums) {
    ll const n = nums.size();
    ll const left_high = n / 2 - 1;
    ll const right_high = n - 1;
    auto left = make_sums(nums, 0, left_high);
    auto right = make_sums(nums, left_high + 1, right_high);
    for (auto& vec : right) std::sort(std::begin(vec), std::end(vec));
    ll min = INT32_MAX;
    for (ll i = 0; i < left.size(); ++i) {
      auto const j = n / 2 - i;
      for (auto n : left[i]) {
        ll const k = binary_search(0, right[j].size(),
                                   [&](auto i) { return n + right[j][i] < 0; });
        if (k != right[j].size()) {
          min = std::min(min, std::abs(n + right[j][k]));
        }
        if (k != 0) {
          min = std::min(min, std::abs(n + right[j][k - 1]));
        }
      }
    }
    return min;
  }
};
