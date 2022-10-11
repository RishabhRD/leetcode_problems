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

int del(std::string_view str, int i, std::vector<int>& dp) {
  if (dp[i] != -1) return dp[i];
  int ans = 1;
  for (int j = i; j < std::size(str); ++j) {
    auto const cur_str = str.substr(i, j - i + 1);
    int const rem_size = std::size(str) - j - 1;
    auto const next_str = str.substr(j + 1, std::min(rem_size, j - i + 1));
    if (cur_str == next_str) {
      ans = std::max(ans, 1 + del(str, j + 1, dp));
    }
  }
  return dp[i] = ans;
}

class Solution {
 public:
  int deleteString(std::string s) {
    auto const n = std::size(s);
    std::vector dp(n, -1);
    return del(s, 0, dp);
  }
};
