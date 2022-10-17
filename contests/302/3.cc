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

auto trim(std::string_view str, int len) {
  return str.substr(std::size(str) - len);
}

auto trim_vec(std::vector<std::string> const& vec, int len) {
  std::vector<std::pair<std::string_view, int>> res(std::size(vec));
  for (int i = 0; i < std::size(vec); ++i) {
    res[i] = {trim(vec[i], len), i};
  }
  return res;
}

auto sorted(std::vector<std::pair<std::string_view, int>> vec) {
  std::sort(std::begin(vec), std::end(vec));
  return vec;
}

class Solution {
 public:
  std::vector<int> smallestTrimmedNumbers(
      std::vector<std::string>& nums, std::vector<std::vector<int>>& queries) {
    auto const max_len = nums[0].size();
    std::vector<std::vector<std::pair<std::string_view, int>>> dp(max_len + 1);
    for (int i = 1; i <= max_len; ++i) {
      dp[i] = sorted(trim_vec(nums, i));
    }
    std::vector<int> res;
    for (auto const& query : queries) {
      auto const k = query[0];
      auto const idx = query[1];
      res.push_back(dp[idx][k - 1].second);
    }
    return res;
  }
};
