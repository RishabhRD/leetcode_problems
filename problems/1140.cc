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

int max_stone(std::vector<int> const &piles, int const cur_idx, int const m,
              bool is_player, std::vector<std::vector<int>> &player_dp,
              std::vector<std::vector<int>> &other_dp) {
  if (cur_idx >= std::size(piles))
    return 0;

  if (is_player) {
    if (2 * m >= std::size(piles) - cur_idx)
      return std::accumulate(std::begin(piles) + cur_idx, std::end(piles), 0);
    if (player_dp[cur_idx][m] != -1)
      return player_dp[cur_idx][m];
    int cur_sum = 0;
    int ans = 0;
    for (int x = 1; x <= 2 * m; ++x) {
      auto i = cur_idx + x - 1;
      if (i >= std::size(piles))
        break;
      cur_sum += piles[i];
      ans = std::max(ans, cur_sum + max_stone(piles, i + 1, std::max(x, m),
                                              false, player_dp, other_dp));
    }
    return player_dp[cur_idx][m] = ans;
  } else {
    if (2 * m >= std::size(piles) - cur_idx)
      return 0;
    if (other_dp[cur_idx][m] != -1)
      return other_dp[cur_idx][m];
    int ans = INT32_MAX;
    for (int x = 1; x <= 2 * m; ++x) {
      auto i = cur_idx + x;
      ans = std::min(
          ans, max_stone(piles, i, std::max(x, m), true, player_dp, other_dp));
    }
    return other_dp[cur_idx][m] = ans;
  }
}

class Solution {
public:
  int stoneGameII(std::vector<int> const &piles) {
    auto const n = std::size(piles);
    std::vector player_dp(n + 1, std::vector(n + 1, -1));
    std::vector other_dp(n + 1, std::vector(n + 1, -1));
    return max_stone(piles, 0, 1, true, player_dp, other_dp);
  }
};
