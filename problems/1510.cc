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

bool is_winner(int n, std::vector<std::optional<bool>> &dp) {
  if (n <= 0)
    return false;
  if (dp[n].has_value()) {
    return dp[n].value();
  }
  for (int i = 1; i * i <= n; ++i) {
    if (!is_winner(n - i * i, dp)) {
      dp[n] = true;
      return true;
    }
  }
  dp[n] = false;
  return false;
}

class Solution {
public:
  bool winnerSquareGame(int n) {
    std::vector dp(n + 1, std::optional<bool>{});
    return is_winner(n, dp);
  }
};
