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

bool can_win(std::bitset<21>& ints, int total,
             std::unordered_map<int, bool>& dp) {
  if (total <= 0) return false;
  auto const formatted_int = ints.to_ulong();
  if (dp.find(formatted_int) != dp.end()) return dp[formatted_int];
  bool var_can_win = false;
  for (int i = 1; i <= 20; ++i) {
    if (ints[i] and !var_can_win) {
      ints[i] = false;
      var_can_win = var_can_win || !can_win(ints, total - i, dp);
      ints[i] = true;
    }
  }
  return dp[formatted_int] = var_can_win;
}

class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (maxChoosableInteger >= desiredTotal) return true;
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
      return false;
    std::bitset<21> ints{};
    for (int i = 1; i <= maxChoosableInteger; ++i) {
      ints[i] = true;
    }
    std::unordered_map<int, bool> dp;
    return can_win(ints, desiredTotal, dp);
  }
};
