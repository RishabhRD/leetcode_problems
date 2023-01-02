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
  int maximumTastiness(std::vector<int>& price, int k) {
    auto const n = std::size(price);
    std::sort(std::begin(price), std::end(price));
    auto is_possible = [&](auto diff) {
      ll cnt = 1;
      ll cur = price[0];
      for (ll i = 1; i < n; ++i) {
        if (price[i] - cur >= diff) {
          ++cnt;
          cur = price[i];
        }
      }
      return cnt >= k;
    };
    return binary_search(0, 1e9 + 1, is_possible) - 1;
  }
};
