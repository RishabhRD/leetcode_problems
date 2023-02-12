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
  int minCapability(std::vector<int>& nums, int k) {
    ll const n = nums.size();
    auto is_not_a_possible_maximum = [&](ll e) {
      ll prev = -1;
      ll total_possible = 0;
      for (ll i = 0; i < n; ++i) {
        if (nums[i] > e) {
          auto const len = i - prev - 1;
          auto const cur_num_possible = len - (len / 2);
          total_possible += cur_num_possible;
          prev = i;
        }
      }
      auto const len = n - 1 - prev;
      total_possible += len - (len / 2);
      return total_possible < k;
    };
    return binary_search(0, 1e9 + 1, is_not_a_possible_maximum);
  }
};
