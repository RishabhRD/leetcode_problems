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

int lis(std::vector<int> const& scores) {
  auto const n = std::size(scores);
  std::vector dp = scores;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (scores[j] <= scores[i]) {
        dp[i] = std::max(dp[i], dp[j] + scores[i]);
      }
    }
  }
  return *std::max_element(std::begin(dp), std::end(dp));
}

class Solution {
 public:
  int bestTeamScore(std::vector<int>& scores, std::vector<int>& ages) {
    auto const n = std::size(scores);
    std::vector<std::pair<int, int>> age_score(n);
    for (int i = 0; i < n; ++i) age_score[i] = {ages[i], scores[i]};
    std::sort(std::begin(age_score), std::end(age_score));
    for (int i = 0; i < n; ++i) scores[i] = age_score[i].second;
    return lis(scores);
  }
};
