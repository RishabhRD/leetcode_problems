#include <algorithm>
#include <array>
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
  int longestIdealString(std::string s, int k) {
    auto const n = std::size(s);
    std::array<std::size_t, 26> dp{0};
    for (auto c : s) {
      std::size_t cur_value = 0;
      for (auto to_diff_char = 'a'; to_diff_char <= 'z'; ++to_diff_char) {
        if (std::abs(to_diff_char - c) <= k) {
          cur_value = std::max(cur_value, 1 + dp[to_diff_char - 'a']);
        }
      }
      dp[c - 'a'] = cur_value;
    }
    return *std::max_element(std::cbegin(dp), std::cend(dp));
  }
};
