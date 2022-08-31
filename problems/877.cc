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

int max_possible(std::vector<int> const& piles, int low, int high,
                 std::vector<std::vector<int>>& dp) {
  if (low > high) return 0;
  if (dp[low][high] >= 0) return dp[low][high];

  auto const low_picked =
      piles[low] + std::min(max_possible(piles, low + 2, high, dp),
                            max_possible(piles, low + 1, high - 1, dp));
  auto const high_picked =
      piles[high] + std::min(max_possible(piles, low, high - 2, dp),
                             max_possible(piles, low + 1, high - 1, dp));

  return dp[low][high] = std::max(low_picked, high_picked);
}

class Solution {
 public:
  bool stoneGame(std::vector<int>& piles) {
    auto const n = std::size(piles);
    std::vector dp(n, std::vector(n, -1));
    auto const max_first_player_score = max_possible(piles, 0, n - 1, dp);

    auto const piles_sum =
        std::accumulate(std::begin(piles), std::end(piles), 0);
    auto const max_second_person_score = piles_sum - max_first_player_score;
    return max_first_player_score > max_second_person_score;
  }
};
