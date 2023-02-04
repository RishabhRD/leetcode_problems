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
  int maximizeWin(std::vector<int>& prizePositions, int k) {
    ll const n = prizePositions.size();
    std::vector<ll> next_pos(n);
    for (ll i = 0; i < n; ++i) {
      auto const next_val = prizePositions[i] + k;
      auto const next_position = binary_search(
          i, n, [&](auto i) { return prizePositions[i] <= next_val; });
      next_pos[i] = next_position;
    }

    std::vector<ll> suffix(n);
    ll max_dist = 0;
    for (ll i = n - 1; i >= 0; --i) {
      auto const cur_dist = next_pos[i] - i;
      max_dist = std::max(max_dist, cur_dist);
      suffix[i] = max_dist;
    }
    ll max_total_dist = 0;
    for (ll i = 0; i < n; ++i) {
      auto cur_dist = next_pos[i] - i;
      if (next_pos[i] != n) {
        cur_dist += suffix[next_pos[i]];
      }
      max_total_dist = std::max(max_total_dist, cur_dist);
    }
    return max_total_dist;
  }
};
