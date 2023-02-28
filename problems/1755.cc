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

std::vector<ll> possible_sums(std::vector<int> const& nums, ll low, ll high) {
  ll const n = high - low + 1;
  ll const max = 1 << n;
  std::vector<ll> res;
  for (ll i = 0; i < max; ++i) {
    std::bitset<32> bs(i);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
      if (bs[i]) {
        sum += nums[low + i];
      }
    }
    res.push_back(sum);
  }
  return res;
}

class Solution {
 public:
  int minAbsDifference(std::vector<int>& nums, int goal) {
    ll const n = nums.size();
    if (n == 1) return std::min(std::abs(nums[0] - goal), std::abs(goal));
    auto const left_high = (n / 2) - 1;
    auto const right_high = n - 1;
    auto const left = possible_sums(nums, 0, left_high);
    auto right = possible_sums(nums, left_high + 1, right_high);
    std::sort(std::begin(right), std::end(right));
    ll min = INT32_MAX;
    for (auto n : left) min = std::min(min, std::abs(n - goal));
    for (auto n : right) min = std::min(min, std::abs(n - goal));
    for (auto n : left) {
      ll const pos_idx = binary_search(
          0, right.size(), [&](auto i) { return n + right[i] < goal; });
      if (pos_idx != right.size()) {
        min = std::min<ll>(min, std::abs(n + right[pos_idx] - goal));
      }
      if (pos_idx != 0) {
        min = std::min<ll>(min, std::abs(n + right[pos_idx - 1] - goal));
      }
    }
    return min;
  }
};
