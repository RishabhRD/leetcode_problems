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

auto get_first_table(std::string_view s) {
  ll const n = s.size();
  std::vector<ll> cur_table(26, n);
  std::vector<std::vector<ll>> idx_table(n + 1, std::vector<ll>(26, n));
  for (ll i = n - 1; i >= 0; --i) {
    cur_table[s[i] - 'a'] = i;
    idx_table[i] = cur_table;
  }
  return idx_table;
}

auto get_last_table(std::string_view s) {
  ll const n = s.size();
  std::vector<ll> cur_table(26, -1);
  std::vector<std::vector<ll>> idx_table(n + 1, std::vector<ll>(26, -1));
  for (ll i = 1; i <= n; ++i) {
    cur_table[s[i - 1] - 'a'] = i - 1;
    idx_table[i] = cur_table;
  }
  return idx_table;
}

class Solution {
 public:
  int minimumScore(std::string s, std::string t) {
    ll const ns = s.size();
    ll const nt = t.size();
    auto const first_table = get_first_table(s);
    auto const last_table = get_last_table(s);
    ll first_idx = -1;
    std::vector<ll> prefix(nt + 1, -1);
    for (ll i = 0; i < nt; ++i) {
      if (first_idx == ns) {
        prefix[i + 1] = ns;
      } else {
        first_idx = first_table[first_idx + 1][t[i] - 'a'];
        prefix[i + 1] = first_idx;
      }
    }

    ll last_idx = ns;
    std::vector<ll> suffix(nt + 1, ns);
    for (ll i = nt - 1; i >= 0; --i) {
      if (last_idx == -1) {
        suffix[i] = -1;
      } else {
        last_idx = last_table[last_idx][t[i] - 'a'];
        suffix[i] = last_idx;
      }
    }
    auto is_possible = [&](ll len) {
      for (ll low = 0, high = len - 1; high < nt; ++low, ++high) {
        if (prefix[low] != ns && suffix[high + 1] != -1 &&
            prefix[low] < suffix[high + 1]) {
          return true;
        }
      }
      return false;
    };
    return binary_search(0, nt + 1,
                         [&](auto len) { return !is_possible(len); });
  }
};
