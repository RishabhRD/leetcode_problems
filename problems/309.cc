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

int dfs(std::vector<int> const& prices, int cur_idx, bool to_buy,
        std::vector<int>& buy_dp, std::vector<int>& sell_dp) {
  if (cur_idx >= std::size(prices)) return 0;

  if (to_buy) {
    if (buy_dp[cur_idx] != -1) return buy_dp[cur_idx];

    return buy_dp[cur_idx] =
               std::max(-prices[cur_idx] +
                            dfs(prices, cur_idx + 1, false, buy_dp, sell_dp),
                        dfs(prices, cur_idx + 1, true, buy_dp, sell_dp));
  } else {
    if (sell_dp[cur_idx] != -1) return sell_dp[cur_idx];
    return sell_dp[cur_idx] =
               std::max(prices[cur_idx] +
                            dfs(prices, cur_idx + 2, true, buy_dp, sell_dp),
                        dfs(prices, cur_idx + 1, false, buy_dp, sell_dp));
  }
}

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    std::vector buy_dp(std::size(prices), -1);
    std::vector sell_dp(std::size(prices), -1);
    return dfs(prices, 0, true, buy_dp, sell_dp);
  }
};
