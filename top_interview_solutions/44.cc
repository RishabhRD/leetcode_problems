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

bool is_match(ll i, ll j, std::string_view s, std::string_view p,
              std::vector<std::vector<ll>>& dp) {
  if (i == s.size() && j == p.size()) {
    return true;
  } else if (j == p.size()) {
    return false;
  }

  if (dp[i][j] != -1) return dp[i][j];

  bool ans = false;
  if (i == s.size()) {
    if (p[j] == '*') {
      ans = ans || is_match(i, j + 1, s, p, dp);
    }
  } else {
    if (s[i] == p[j] || p[j] == '?') {
      ans = ans || is_match(i + 1, j + 1, s, p, dp);
    } else if (p[j] == '*') {
      ans = ans || is_match(i, j + 1, s, p, dp) || is_match(i + 1, j, s, p, dp);
    }
  }
  return dp[i][j] = ans;
}

class Solution {
 public:
  bool isMatch(std::string s, std::string p) {
    ll const n = s.size();
    ll const m = p.size();
    std::vector dp(n + 1, std::vector(m + 1, -1ll));

    return is_match(0, 0, s, p, dp);
  }
};
