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
  auto const n = str.size();
  std::vector dp(n, std::vector(n, false));
  for (ll i = 0; i < n; ++i) dp[i][i] = true;
  for (ll i = 0; i < n - 1; ++i) {
    if (str[i] == str[i + 1]) dp[i][i + 1] = true;
  }
  for (ll len = 3; len <= n; ++len) {
    for (ll i = 0; i <= n - len; ++i) {
      auto const j = i + len - 1;
      dp[i][j] = (str[i] == str[j]) && dp[i + 1][j - 1];
    }
  }
  return dp;
}

ll dfs(ll i, std::vector<std::vector<bool>> const& is_palindrome,
       std::vector<ll>& dp, ll k) {
  auto const n = is_palindrome.size();
  if (i >= n) return 0;
  if (dp[i] != -1) return dp[i];
  ll ans = 0;
  for (ll j = i; j < n; ++j) {
    if (is_palindrome[i][j] && j - i + 1 >= k) {
      ans = std::max(ans, 1 + dfs(j + 1, is_palindrome, dp, k));
    } else {
      ans = std::max(ans, dfs(j + 1, is_palindrome, dp, k));
    }
  }
  return dp[i] = ans;
}

class Solution {
 public:
  int maxPalindromes(std::string s, int k) {
    auto const n = std::size(s);
    auto const is_palindrome = preprocess(s);
    std::vector<ll> dp(n, -1);
    return dfs(0, is_palindrome, dp, k);
  }
};
