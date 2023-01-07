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
  std::vector dp(n, std::vector(n, 0ll));
  for (ll i = 0; i < n - 1; ++i) {
    if (str[i] != str[i + 1]) dp[i][i + 1] = 1;
  }
  for (ll len = 3; len <= n; ++len) {
    for (ll i = 0; i <= n - len; ++i) {
      auto const j = i + len - 1;
      if (str[i] != str[j]) {
        dp[i][j] = 1 + dp[i + 1][j - 1];
      } else {
        dp[i][j] = dp[i + 1][j - 1];
      }
    }
  }
  return dp;
}

ll dfs(ll i, ll k, std::vector<std::vector<ll>> const& num_changes,
       std::vector<std::vector<ll>>& dp) {
  auto const n = num_changes.size();
  if (i >= n) {
    if (k > 0)
      return n + 1;
    else
      return 0;
  }
  if (k == 0) {
    return n + 1;
  }
  if (dp[i][k] != -1) return dp[i][k];
  ll ans = n + 1;
  for (ll j = i; j < n; ++j) {
    ans = std::min(ans, num_changes[i][j] + dfs(j + 1, k - 1, num_changes, dp));
  }
  return dp[i][k] = ans;
}

class Solution {
 public:
  int palindromePartition(std::string s, int k) {
    auto const n = std::size(s);
    auto const num_changes = preprocess(s);
    std::vector dp(n, std::vector<ll>(k + 1, -1));
    return dfs(0, k, num_changes, dp);
  }
};
