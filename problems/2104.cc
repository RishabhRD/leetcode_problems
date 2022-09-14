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

template <typename Comp>
long long subarray_ranges_sum(std::vector<int> const& nums, Comp cmp) {
  auto const n = std::size(nums);
  std::vector left(n, 0ll);
  std::vector right(n, 0ll);

  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (not std::empty(st) and cmp(nums[i], nums[st.top()])) {
      st.pop();
    }
    if (st.empty())
      left[i] = i + 1;
    else
      left[i] = i - st.top();
    st.push(i);
  }

  st = std::stack<int>{};
  for (int i = n - 1; i >= 0; --i) {
    while (not std::empty(st) and
           (cmp(nums[i], nums[st.top()]) || nums[i] == nums[st.top()])) {
      st.pop();
    }
    if (st.empty()) {
      right[i] = n - i;
    } else {
      right[i] = st.top() - i;
    }
    st.push(i);
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += nums[i] * left[i] * right[i];
  }
  return ans;
}

class Solution {
 public:
  long long subArrayRanges(std::vector<int> const& nums) {
    return subarray_ranges_sum(nums, std::greater{}) -
           subarray_ranges_sum(nums, std::less{});
  }
};
