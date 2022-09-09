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
  int findUnsortedSubarray(std::vector<int> const& nums) {
    std::stack<int> st;
    int low = INT32_MAX;
    int high = INT32_MAX - 1;

    auto const n = std::size(nums);
    for (int i = 0; i < n; ++i) {
      if (not std::empty(st) and nums[st.top()] > nums[i]) {
        auto const to_push = st.top();
        while (not std::empty(st) and nums[st.top()] > nums[i]) {
          low = std::min(low, st.top());
          st.pop();
        }
        high = i;
        st.push(to_push);
      } else {
        st.push(i);
      }
    }
    return high - low + 1;
  }
};
