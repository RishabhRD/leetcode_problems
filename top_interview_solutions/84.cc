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

auto make_prev_smaller(std::vector<int> const& nums) {
  ll const n = nums.size();
  std::vector prev(n, -1ll);

  std::vector<ll> stack;
  for (ll i = 0; i < n; ++i) {
    while (stack.size() && nums[stack.back()] >= nums[i]) {
      stack.pop_back();
    }
    if (stack.size()) {
      prev[i] = stack.back();
    }
    stack.push_back(i);
  }

  return prev;
}

auto make_next_smaller(std::vector<int> const& nums) {
  ll const n = nums.size();
  std::vector next(n, n);

  std::vector<ll> stack;
  for (ll i = n - 1; i >= 0; --i) {
    while (stack.size() && nums[stack.back()] >= nums[i]) {
      stack.pop_back();
    }
    if (stack.size()) {
      next[i] = stack.back();
    }
    stack.push_back(i);
  }

  return next;
}

class Solution {
 public:
  int largestRectangleArea(std::vector<int>& heights) {
    ll const n = heights.size();
    auto const prev_smaller = make_prev_smaller(heights);
    auto const next_smaller = make_next_smaller(heights);

    ll max = 0;

    for (ll i = 0; i < n; ++i) {
      max = std::max(max, heights[i] * ((i - prev_smaller[i]) +
                                        (next_smaller[i] - i) - 1));
    }

    return max;
  }
};
