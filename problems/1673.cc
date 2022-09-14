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
  std::vector<int> mostCompetitive(std::vector<int> const& nums, int k) {
    auto const n = std::size(nums);
    std::vector<int> st;
    st.reserve(n);
    for (int i = 0; i < n; ++i) {
      while (not std::empty(st) and st.back() > nums[i] and
             st.size() - 1 + n - i >= k) {
        st.pop_back();
      }
      if (st.size() < k) st.push_back(nums[i]);
    }
    return st;
  }
};
