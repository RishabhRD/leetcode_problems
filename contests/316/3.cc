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

ll mul(ll a, ll b) { return a * b; }

ll make_equal_to(std::vector<int> const& nums, std::vector<int> const& cost,
                 ll k) {
  auto const n = std::size(nums);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += mul(std::abs(nums[i] - k), cost[i]);
  }
  return ans;
}

template <typename Predicate>
ll binary_search(ll low, ll high, Predicate&& is_possible) {
  if (low >= high) return low;
  auto const mid = (low + high) / 2;
  if (is_possible(mid)) {
    return binary_search(low, mid, is_possible);
  } else {
    return binary_search(mid + 1, high, is_possible);
  }
}

class Solution {
 public:
  ll minCost(std::vector<int>& nums, std::vector<int>& cost) {
    return make_equal_to(nums, cost, binary_search(0, 1e6, [&](auto mid) {
                           return make_equal_to(nums, cost, mid) <
                                  make_equal_to(nums, cost, mid + 1);
                         }));
  }
};
