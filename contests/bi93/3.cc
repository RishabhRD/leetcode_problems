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

bool is_possible(std::vector<int>& stones, ll k) {
  auto const n = stones.back();
  std::set<int> incr{std::begin(stones), std::end(stones)};
  std::set<int, std::greater<>> decr{std::begin(stones), std::end(stones),
                                     std::greater<>{}};
  ll cur = stones[0];
  while (cur != n) {
    std::cout << cur << std::endl;
    auto const target = cur + k;
    auto const itr = decr.lower_bound(target);
    if (itr == std::end(decr) || *itr == cur) {
      return false;
    }
    cur = *itr;
    decr.erase(cur);
    incr.erase(cur);
  }
  while (cur != stones[0]) {
    std::cout << cur << std::endl;
    auto const target = cur - k;
    auto const itr = incr.lower_bound(target);
    if (itr == std::end(incr) || *itr == cur) {
      return false;
    }
    cur = *itr;
    decr.erase(cur);
    incr.erase(cur);
  }
  return true;
}

template <typename F>
ll bs(ll low, ll high, F&& f) {
  if (low >= high) return low;
  auto const mid = (low + ((high - low) / 2));
  if (f(mid)) {
    return bs(mid + 1, high, f);
  } else {
    return bs(low, mid, f);
  }
}

class Solution {
 public:
  int maxJump(std::vector<int>& stones) {
    // auto const low = 0;
    // auto const high = stones.back() - stones.front() + 1;
    // return bs(low, high, [&](auto k) { return !is_possible(stones, k); });
    int ans = 0;
    for (ll i = 2; i < std::size(stones); ++i) {
      ans = std::max(ans, stones[i] - stones[i - 2]);
    }
    ans = std::max(ans, stones[1] - stones[0]);
    ans = std::max(
        ans, stones[std::size(stones) - 1] - stones[std::size(stones) - 2]);
    return ans;
  }
};
