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

int max_profit(int i, bool to_buy, std::vector<int> const& prices, int fee,
               std::vector<int>& buy_dp, std::vector<int>& sell_dp) {
  if (i >= std::size(prices)) return 0;
  if (to_buy) {
    if (buy_dp[i] != INT32_MIN) {
      return buy_dp[i];
    }
    return buy_dp[i] = std::max({
               max_profit(i + 1, false, prices, fee, buy_dp, sell_dp) -
                   prices[i],
               max_profit(i + 1, true, prices, fee, buy_dp, sell_dp),
           });
  } else {
    if (sell_dp[i] != INT32_MIN) {
      return sell_dp[i];
    }
    return sell_dp[i] = std::max({
               prices[i] - fee +
                   max_profit(i + 1, true, prices, fee, buy_dp, sell_dp),
               max_profit(i + 1, false, prices, fee, buy_dp, sell_dp),
           });
  }
}

class Solution {
 public:
  int maxProfit(std::vector<int> const& prices, int fee) {
    auto const n = std::size(prices);
    std::vector buy_dp(n, INT32_MIN);
    std::vector sell_dp(n, INT32_MIN);
    return max_profit(0, true, prices, fee, buy_dp, sell_dp);
  }
};
