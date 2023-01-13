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

class Solution {
 public:
  int minimumCardPickup(std::vector<int>& cards) {
    auto const n = cards.size();
    std::unordered_map<ll, ll> idx;
    ll min_len = n + 1;
    for (ll i = 0; i < n; ++i) {
      if (idx.find(cards[i]) == idx.end()) {
        idx[cards[i]] = i;
      } else {
        auto const old_idx = idx[cards[i]];
        auto const new_idx = i;
        idx[cards[i]] = i;
        min_len = std::min(min_len, new_idx - old_idx + 1);
      }
    }
    if (min_len == n + 1) return -1;
    return min_len;
  }
};
