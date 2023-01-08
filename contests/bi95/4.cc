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
ll binary_search(ll low, ll high, Predicate &&predicate) {
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
  long long maxPower(std::vector<int> &stations_, int r, int k) {
    std::vector<ll> stations{std::begin(stations_), std::end(stations_)};
    ll const n = stations.size();
    auto is_possible = [&](ll max) {
      std::vector<ll> cur_stations{stations};
      ll cur_k = k;
      ll low = (-r) - 1;
      ll high = 0;
      ll cur_value = 0;
      for (; high < r; ++high) cur_value += cur_stations[high];
      for (ll i = 0; i < n; ++i, ++high, ++low) {
        if (high < n) {
          cur_value += cur_stations[high];
        }
        if (low >= 0) {
          cur_value -= cur_stations[low];
        }
        if (cur_value >= max) continue;
        auto const diff = max - cur_value;
        auto const right = std::min<ll>(high, n - 1);
        cur_stations[right] += diff;
        cur_value += diff;
        cur_k -= diff;
      }
      return cur_k >= 0;
    };
    // std::cout << is_possible(12) << std::endl;
    return binary_search(0, 1e11, is_possible) - 1;
  }
};
