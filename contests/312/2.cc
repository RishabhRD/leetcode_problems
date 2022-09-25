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
  int longestSubarray(std::vector<int>& nums) {
    auto max_ele = *std::max_element(std::begin(nums), std::end(nums));
    int max_ans = 0;
    int cur_ans = 0;
    auto prev_ele = -1;
    for (int ele : nums) {
      if (ele == max_ele) {
        if (prev_ele == ele) ++cur_ans;
        max_ans = std::max(max_ans, cur_ans);
      } else {
        cur_ans = 0;
      }
      prev_ele = ele;
    }
    return max_ans + 1;
  }
};
