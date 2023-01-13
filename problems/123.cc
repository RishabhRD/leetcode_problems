#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

ll dfs(ll i, ll state, std::vector<int> const& prices,
       std::vector<std::vector<ll>>& dp) {
  if (state == 4) return 0;
  if (i >= prices.size()) {
    if (state == 0 || state == 2 || state == 4)
      return 0;
    else
      return INT32_MIN;
  }
  if (dp[i][state] != -1) return dp[i][state];
  if (state == 0) {
    return dp[i][state] = std::max(dfs(i + 1, state, prices, dp),
                                   -prices[i] + dfs(i + 1, 1, prices, dp));
  } else if (state == 1) {
    return dp[i][state] = std::max(dfs(i + 1, state, prices, dp),
                                   prices[i] + dfs(i + 1, 2, prices, dp));
  } else if (state == 2) {
    return dp[i][state] = std::max(dfs(i + 1, state, prices, dp),
                                   -prices[i] + dfs(i + 1, 3, prices, dp));
  } else {
    return dp[i][state] = std::max<ll>(dfs(i + 1, state, prices, dp),
                                       prices[i] + dfs(i + 1, 4, prices, dp));
  }
}

class Solution {
 public:
  int maxProfit(std::vector<int> const& prices) {
    auto const n = prices.size();
    std::vector dp(n, std::vector(4, -1ll));
    return dfs(0, 0, prices, dp);
  }
};
