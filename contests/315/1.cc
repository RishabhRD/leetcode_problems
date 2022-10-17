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
  int findMaxK(std::vector<int>& nums) {
    std::unordered_set<int> st;
    for (auto num : nums) {
      st.insert(num);
    }
    int max_ele = INT32_MIN;
    for (auto num : nums) {
      if (st.find(-num) != st.end()) {
        max_ele = std::max(max_ele, num);
      }
    }
    if (max_ele <= 0) return -1;
    return max_ele;
  }
};
