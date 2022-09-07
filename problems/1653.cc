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

int dfs(int i, std::string_view str, std::vector<int>& dp,
        std::vector<int> const& suffix_a) {
  if (i == std::size(str)) return 0;
  if (dp[i] != -1) return dp[i];

  if (str[i] == 'b') {
    return dp[i] = std::min(suffix_a[i], 1 + dfs(i + 1, str, dp, suffix_a));
  } else {
    return dp[i] = dfs(i + 1, str, dp, suffix_a);
  }
}

auto const make_suffix_a(std::string_view str) {
  std::vector suffix_a(std::size(str), 0);
  auto cnt_a = 0;
  for (int i = std::size(str) - 1; i >= 0; i--) {
    cnt_a += (str[i] == 'a');
    suffix_a[i] = cnt_a;
  }
  return suffix_a;
}

class Solution {
 public:
  int minimumDeletions(std::string s) {
    std::vector dp(std::size(s), -1);
    auto const suffix_a = make_suffix_a(s);
    return dfs(0, s, dp, suffix_a);
  }
};
