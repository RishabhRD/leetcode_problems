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

bool check_partitioning(ll i, ll k,
                        std::vector<std::vector<bool>> const& is_palindrome,
                        std::vector<std::vector<ll>>& dp) {
  if (i >= is_palindrome.size()) return k == 0;
  if (k == 0) return false;
  if (dp[i][k] != -1) return dp[i][k];
  bool ans = false;
  for (ll j = i; j < is_palindrome.size(); ++j) {
    if (is_palindrome[i][j]) {
      ans = ans || check_partitioning(j + 1, k - 1, is_palindrome, dp);
    }
  }
  return dp[i][k] = ans;
}

class Solution {
 public:
  bool checkPartitioning(std::string s) {
    auto const n = s.size();
    auto const is_palindrome = preprocess(s);
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(4, -1));
    return check_partitioning(0, 3, is_palindrome, dp);
  }
};
