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
ll bs(ll low, ll high, Predicate &&predicate) {
  if (low >= high) return low;
  auto const mid = low + (high - low) / 2;
  if (predicate(mid)) {
    return bs(mid + 1, high, predicate);
  } else {
    return bs(low, mid, predicate);
  }
}

class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    return bs(1, m * n + 1, [&](auto x) {
      ll cnt = 0;
      for (ll i = 1; i <= m; ++i) {
        cnt += std::min<ll>(x / i, n);
      }
      return cnt < k;
    });
  }
};
