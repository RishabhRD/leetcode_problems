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
  int totalSteps(std::vector<int>& nums) {
    int max_deletion = 0;
    auto const n = std::size(nums);
    std::stack<int> st;
    std::vector<int> max_steps(n);
    for (int i = n - 1; i >= 0; --i) {
      while (not st.empty() and nums[i] > nums[st.top()]) {
        max_steps[i] = std::max(max_steps[i] + 1, max_steps[st.top()]);
        st.pop();
      }
      st.push(i);
      max_deletion = std::max(max_deletion, max_steps[i]);
    }
    return max_deletion;
  }
};
