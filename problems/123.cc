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

class Solution {
 public:
  int maxProfit(std::vector<int> const& prices) {
    auto profit2 = INT32_MIN;
    auto profit1 = INT32_MIN;
    auto buy1 = INT32_MAX;
    auto buy2 = INT32_MAX;
    auto const n = std::size(prices);
    for (int i = 0; i < n; ++i) {
      buy1 = std::min(buy1, prices[i]);
      profit1 = std::max(profit1, prices[i] - buy1);
      buy2 = std::min(buy2, prices[i] - profit1);
      profit2 = std::max(profit2, prices[i] - buy2);
    }
    return profit2;
  }
};
