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
  int takeCharacters(std::string s, int k) {
    std::vector<ll> num_a({0});
    std::vector<ll> num_b({0});
    std::vector<ll> num_c({0});
    {
      auto cur_a = 0;
      auto cur_b = 0;
      auto cur_c = 0;
      for (auto c : s) {
        if (c == 'a') ++cur_a;
        if (c == 'b') ++cur_b;
        if (c == 'c') ++cur_c;
        num_a.push_back(cur_a);
        num_b.push_back(cur_b);
        num_c.push_back(cur_c);
      }
    }
    if (num_a.back() < k || num_b.back() < k || num_c.back() < k) return -1;
    auto const n = std::size(s);

    auto cur_a = 0;
    auto cur_b = 0;
    auto cur_c = 0;
    ll ans = n;
    for (ll i = n; i >= 0; --i) {
      if (i != n) {
        if (s[i] == 'a') ++cur_a;
        if (s[i] == 'b') ++cur_b;
        if (s[i] == 'c') ++cur_c;
      }
      auto const target_a = std::max(k - cur_a, 0);
      auto const target_b = std::max(k - cur_b, 0);
      auto const target_c = std::max(k - cur_c, 0);
      auto const idx_a =
          binary_search(0, i + 1, [&](auto i) { return num_a[i] < target_a; });
      auto const idx_b =
          binary_search(0, i + 1, [&](auto i) { return num_b[i] < target_b; });
      auto const idx_c =
          binary_search(0, i + 1, [&](auto i) { return num_c[i] < target_c; });
      auto const idx = std::max({idx_a, idx_b, idx_c});
      ans = std::min<ll>(ans, (idx + n - i));
    }
    return ans;
  }
};
