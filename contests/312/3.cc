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

auto make_non_decreasing(std::vector<int> const& nums, int k) {
  auto const n = std::size(nums);
  std::vector<bool> is_non_decreasing(n, false);
  std::deque<int> st;
  int low = n - 1;
  for (int high = n - 1; high >= 0; --high) {
    while (not std::empty(st) and nums[high] > nums[st.back()]) {
      st.pop_back();
    }
    st.push_back(high);
    if (low - high + 1 > k) {
      if (st.front() == low) {
        st.pop_front();
      }
      --low;
    }
    if (st.size() == k) is_non_decreasing[high] = true;
  }
  return is_non_decreasing;
}

auto make_non_increasing(std::vector<int> const& nums, int k) {
  auto const n = std::size(nums);
  std::vector<bool> is_non_increasing(n, false);
  std::deque<int> st;
  int low = 0;
  for (int high = 0; high < n; ++high) {
    while (not std::empty(st) and nums[high] > nums[st.back()]) {
      st.pop_back();
    }
    st.push_back(high);
    if (high - low + 1 > k) {
      if (st.front() == low) {
        st.pop_front();
      }
      ++low;
    }
    if (st.size() == k) is_non_increasing[high] = true;
  }
  return is_non_increasing;
}

class Solution {
 public:
  std::vector<int> goodIndices(std::vector<int>& nums, int k) {
    auto const n = std::size(nums);
    auto const is_non_increasing = make_non_increasing(nums, k);
    auto const is_non_decreasing = make_non_decreasing(nums, k);
    std::vector<int> res;
    for (int i = k; i < n - k; ++i) {
      if (is_non_increasing[i - 1] and is_non_decreasing[i + 1])
        res.push_back(i);
    }
    return res;
  }
};
