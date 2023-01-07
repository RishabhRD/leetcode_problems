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

ll num_ways(ll i, ll state, std::string_view str,
            std::vector<std::vector<ll>>& dp) {
  if (state == 5 || state == 6) return 1;
  if (i >= str.size()) return 0;
  if (dp[i][state] != -1) return dp[i][state];
  ll ans = 0;
  ans += num_ways(i + 1, state, str, dp);
  if (state == 0) {
    if (str[i] == '0') {
      ans += num_ways(i + 1, 1, str, dp);
    } else {
      ans += num_ways(i + 1, 2, str, dp);
    }
  } else if (state == 1) {
    if (str[i] == '1') {
      ans += num_ways(i + 1, 3, str, dp);
    }
  } else if (state == 2) {
    if (str[i] == '0') {
      ans += num_ways(i + 1, 4, str, dp);
    }
  } else if (state == 3) {
    if (str[i] == '0') {
      ans += num_ways(i + 1, 5, str, dp);
    }
  } else if (state == 4) {
    if (str[i] == '1') {
      ans += num_ways(i + 1, 6, str, dp);
    }
  }
  return dp[i][state] = ans;
}

class Solution {
 public:
  long long numberOfWays(std::string s) {
    auto const n = std::size(s);
    std::vector dp(n, std::vector(7, -1ll));
    return num_ways(0, 0, s, dp);
  }
};
