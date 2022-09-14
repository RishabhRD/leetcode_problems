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
  std::vector<int> canSeePersonsCount(std::vector<int>& heights) {
    auto const n = std::size(heights);
    std::stack<int> st;
    std::vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
      int sum = 0;
      while (not std::empty(st) and heights[st.top()] < heights[i]) {
        st.pop();
        ++sum;
      }
      ans[i] = sum + (!st.empty());
      st.push(i);
    }
    return ans;
  }
};
