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

// [84,80,43,8,80,88,43,14,100,88]
// [32,32,42,68,68,100,42,84,14,8]
// Output: 117
// Expected: 48

using ll = long long;

class Solution {
 public:
  long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
    std::unordered_map<ll, ll> cnt1;
    std::unordered_map<ll, ll> cnt2;
    std::unordered_map<ll, ll> cnt;
    for (auto n : basket1) {
      ++cnt1[n];
      ++cnt[n];
    }
    for (auto n : basket2) {
      ++cnt2[n];
      ++cnt[n];
    }
    std::vector<ll> nums;
    for (auto [k, v] : cnt) {
      if (v % 2) return -1;
      auto const v1 = cnt1[k];
      auto const v2 = cnt2[k];
      auto const to_exchange = std::abs(v1 - v2) / 2;
      for (ll i = 0; i < to_exchange; ++i) {
        nums.push_back(k);
      }
    }
    std::sort(std::begin(nums), std::end(nums));
    ll sum = 0;
    ll const min =
        std::min(*std::min_element(std::begin(basket1), std::end(basket1)),
                 *std::min_element(std::begin(basket2), std::end(basket2)));
    ll size = nums.size() / 2;
    for (ll i = 0; i < size; ++i) {
      sum += std::min(2 * min, nums[i]);
    }
    return sum;
  }
};
