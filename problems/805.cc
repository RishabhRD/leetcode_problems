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
    for (ll j = 0; j < n; ++j) {
      if (bs[j]) {
        sum += nums[low + j];
      }
    }
    res[bs.count()].push_back(sum);
  }
  return res;
}

class Solution {
 public:
  bool splitArraySameAverage(std::vector<int>& nums) {
    ll const n = nums.size();
    ll const left_high = n / 2 - 1;
    ll const right_high = n - 1;
    auto left = make_sums(nums, 0, left_high);
    auto right = make_sums(nums, left_high + 1, right_high);
    for (auto& vec : right) std::sort(std::begin(vec), std::end(vec));
    ll const sum = std::reduce(std::begin(nums), std::end(nums), 0);
    for (auto& vec : right) std::sort(std::begin(vec), std::end(vec));
    for (ll i = 0; i < left.size(); ++i) {
      for (ll j = 0; j < right.size(); ++j) {
        if ((i == 0 && j == 0) ||
            (i == left.size() - 1 && j == right.size() - 1))
          continue;
        for (auto ele : left[i]) {
          auto const k = binary_search(0, right[j].size(), [&](auto idx) {
            return (right[j][idx] + ele) * n < sum * (i + j);
          });
          if (k != right[j].size() && (right[j][k] + ele) * n == sum * (i + j))
            return true;
        }
      }
    }
    return false;
  }
};
