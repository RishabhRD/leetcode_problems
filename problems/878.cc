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

constexpr ll mod = 1e9 + 7;

class Solution {
 public:
  int nthMagicalNumber(ll n, ll a, ll b) {
    auto const c = (a * b) / std::gcd(a, b);
    return binary_search(0, 1e18,
                         [&](ll ele) {
                           return ((ele / a) + (ele / b) - (ele / c)) < n;
                         }) %
           mod;
  }
};
