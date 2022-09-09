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
  bool find132pattern(std::vector<int> const& nums) {
    auto const n = std::size(nums);
    std::stack<int> st;
    int third = INT32_MIN;
    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] < third) return true;
      while (not std::empty(st) and nums[i] > st.top()) {
        third = st.top();
        st.pop();
      }
      st.push(nums[i]);
    }
    return false;
  }
};
