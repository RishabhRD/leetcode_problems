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
  int smallestDistancePair(std::vector<int>& nums, int k) {
    std::vector<ll> unq_nums;
    std::vector<ll> cnt(1e6 + 1);
    for (auto n : nums) ++cnt[n];
    for (ll i = 0; i <= 1e6; ++i) {
      if (cnt[i]) unq_nums.push_back(i);
    }
    std::vector<ll> pre_cnt(1e6 + 1);
    pre_cnt[0] = cnt[0];
    for (ll i = 1; i <= 1e6; ++i) {
      pre_cnt[i] = cnt[i] + pre_cnt[i - 1];
    }
    auto get_sum = [&](auto i, auto j) {
      if (i == 0)
        return pre_cnt[j];
      else
        return pre_cnt[j] - pre_cnt[i - 1];
    };
    auto count_pair_with_dist_less_than_from_element = [&](auto e, auto d) {
      auto const high = std::min<ll>(e + d, 1e6);
      auto const low = std::min<ll>(e + 1, 1e6);
      if (d == 0) {
        return ((cnt[e] * (cnt[e] - 1)) / 2);
      }
      return cnt[e] * get_sum(low, high) + ((cnt[e] * (cnt[e] - 1)) / 2);
    };

    auto count_pair_with_dist_less_than = [&](auto d) {
      ll sum = 0;
      for (auto n : unq_nums) {
        sum += count_pair_with_dist_less_than_from_element(n, d);
      }
      return sum;
    };
    return binary_search(
        0, 1e9, [&](auto d) { return count_pair_with_dist_less_than(d) < k; });
  }
};
