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

using ll = long long;

auto preprocess(std::string_view str) {
  auto const n = std::size(str);
  std::vector dp(n, std::vector(n, false));
  for (ll i = 0; i < n; ++i) {
    dp[i][i] = true;
  }
  for (ll i = 0; i < n - 1; ++i) {
    if (str[i] == str[i + 1]) dp[i][i + 1] = true;
  }
  for (ll len = 3; len <= n; ++len) {
    for (ll i = 0; i <= n - len; ++i) {
      auto const j = i + len - 1;
      if (str[i] == str[j]) {
        dp[i][j] = dp[i + 1][j - 1];
      }
    }
  }
  return dp;
}

ll min_cut(ll i, std::vector<std::vector<bool>> const& is_palindrome,
           std::vector<ll>& dp) {
  if (i >= is_palindrome.size()) return 0;
  if (dp[i] != -1) return dp[i];
  ll ans = is_palindrome.size();
  for (ll j = i; j < is_palindrome.size(); ++j) {
    if (is_palindrome[i][j])
      ans = std::min(ans, 1 + min_cut(j + 1, is_palindrome, dp));
  }
  return dp[i] = ans;
}

class Solution {
 public:
  int minCut(std::string s) {
    auto const n = std::size(s);
    auto const is_palindrome = preprocess(s);
    std::vector dp(n, -1ll);
    return min_cut(0, is_palindrome, dp) - 1;
    // for (auto n : dp) std::cout << n << std::endl;
  }
};
