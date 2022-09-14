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

class Solution {
 public:
  int maxWidthRamp(std::vector<int> const& nums) {
    auto const n = std::size(nums);
    auto idx_cmp = [&](auto i, auto j) { return nums[i] > nums[j]; };
    std::vector<int> st({0});
    for (int i = 1; i < n; ++i) {
      if (nums[st.back()] > nums[i]) {
        st.push_back(i);
      }
    }
    auto ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      while (not std::empty(st) and nums[i] >= nums[st.back()]) {
        ans = std::max(ans, i - st.back());
        st.pop_back();
      }
    }
    return ans;
  }
};
