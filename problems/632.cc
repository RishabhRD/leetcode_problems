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

auto merge(std::vector<std::vector<int>> const& nums) {
  std::vector<std::pair<int, int>> res;
  for (int i = 0; i < std::size(nums); ++i) {
    auto const vec = nums[i];
    std::transform(std::begin(vec), std::end(vec), std::back_inserter(res),
                   [=](auto ele) {
                     return std::pair{ele, i};
                   });
  }
  std::sort(std::begin(res), std::end(res));
  return res;
}

class Solution {
 public:
  std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
    auto const merged_vector = merge(nums);
    auto const n = std::size(merged_vector);
    std::unordered_map<int, int> st;
    auto push_to_sliding_window = [&](int idx) {
      ++st[merged_vector[idx].second];
    };
    int low = 0;
    auto shrink_sliding_window = [&] {
      --st[merged_vector[low].second];
      if (st[merged_vector[low].second] == 0)
        st.erase(merged_vector[low].second);
    };
    auto sliding_window_satisfies = [&] {
      return st.size() == std::size(nums);
    };
    int min_low = 0;
    int min_high = 0;
    int min_ans = INT32_MAX;
    for (int high = 0; high < n; ++high) {
      push_to_sliding_window(high);
      while (sliding_window_satisfies()) {
        auto const low_val = merged_vector[low].first;
        auto const high_val = merged_vector[high].first;
        if (high_val - low_val < min_ans) {
          min_low = low_val;
          min_high = high_val;
          min_ans = min_high - min_low;
        }
        shrink_sliding_window();
        ++low;
      }
    }
    return std::vector({min_low, min_high});
  }
};
