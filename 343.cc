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

ll integer_break(ll n, std::vector<ll>& dp) {
  if (dp[n] != -1) return dp[n];
  ll max_ans = n;
  for (ll i = 1; i < n; ++i) {
    max_ans =
        std::max(max_ans, integer_break(i, dp) * integer_break(n - i, dp));
  }
  return dp[n] = max_ans;
}

class Solution {
 public:
  int integerBreak(int n) {
    std::vector dp(n + 1, -1ll);
    ll ans = 0;
    for (ll i = 1; i < n; ++i) {
      ans = std::max(ans, integer_break(i, dp) * integer_break(n - i, dp));
    }
    return ans;
  }
};
