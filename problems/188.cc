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

int dfs(int k, std::vector<int> const& prices, int cur_idx,
        std::vector<std::vector<int>>& buy_dp,
        std::vector<std::vector<int>>& sell_dp, bool to_buy) {
  if (k == 0) return 0;
  if (cur_idx == std::size(prices)) return 0;
  if (to_buy) {
    if (buy_dp[k][cur_idx] != -1) {
      return buy_dp[k][cur_idx];
    }
    return buy_dp[k][cur_idx] =
               std::max(dfs(k, prices, cur_idx + 1, buy_dp, sell_dp, true),
                        -prices[cur_idx] + dfs(k, prices, cur_idx + 1, buy_dp,
                                               sell_dp, false));
  } else {
    if (sell_dp[k][cur_idx] != -1) {
      return sell_dp[k][cur_idx];
    }
    return sell_dp[k][cur_idx] =
               std::max(dfs(k, prices, cur_idx + 1, buy_dp, sell_dp, false),
                        prices[cur_idx] + dfs(k - 1, prices, cur_idx + 1,
                                              buy_dp, sell_dp, true));
  }
}

class Solution {
 public:
  int maxProfit(int k, std::vector<int>& prices) {
    std::vector buy_dp(k + 1, std::vector(std::size(prices), -1));
    std::vector sell_dp(k + 1, std::vector(std::size(prices), -1));
    return dfs(k, prices, 0, buy_dp, sell_dp, true);
  }
};
