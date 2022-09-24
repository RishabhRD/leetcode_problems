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

auto cost(long long n) { return (n * (n + 1)) / 2; }

auto max_profit_sorted(std::vector<int> const& inventory, int orders) {
  constexpr static int mod = 1e9 + 7;
  auto const begin = std::begin(inventory);
  auto cur = std::begin(inventory);
  long long total_cost = 0;
  while (orders) {
    auto next =
        std::upper_bound(cur, std::end(inventory), *cur, std::greater{});
    auto const dist = std::distance(begin, next);
    auto const orders_covered = dist * (*cur - *next);
    if (orders - orders_covered < 0) {
      auto const num_full_covered = orders / dist;
      auto const num_last_covered = orders % dist;
      auto const pseudo_next_val = *cur - num_full_covered;
      total_cost += dist * (cost(*cur) - cost(pseudo_next_val));
      total_cost += pseudo_next_val * num_last_covered;
      orders = 0;
    } else {
      auto const rate = cost(*cur) - cost(*next);
      total_cost += rate * dist;
      orders = orders - orders_covered;
    }
    cur = next;
  }
  return total_cost % mod;
}

class Solution {
 public:
  int maxProfit(std::vector<int>& inventory, int orders) {
    std::sort(std::begin(inventory), std::end(inventory), std::greater{});
    inventory.push_back(0);
    return max_profit_sorted(inventory, orders);
  }
};
