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

bool can_make_square(int len1, int len2, int len3, int len4, int i,
                     std::vector<int>& matchsticks, int target) {
  if (i == std::size(matchsticks)) {
    return len1 == len2 and len2 == len3 and len3 == len4;
  }
  auto const cur_len = matchsticks[i];
  if (cur_len + len1 <= target and
      can_make_square(len1 + cur_len, len2, len3, len4, i + 1, matchsticks,
                      target)) {
    return true;
  }
  if (cur_len + len2 <= target and
      can_make_square(len1, len2 + cur_len, len3, len4, i + 1, matchsticks,
                      target)) {
    return true;
  }
  if (cur_len + len3 <= target and
      can_make_square(len1, len2, len3 + cur_len, len4, i + 1, matchsticks,
                      target)) {
    return true;
  }
  if (cur_len + len4 <= target and
      can_make_square(len1, len2, len3, len4 + cur_len, i + 1, matchsticks,
                      target)) {
    return true;
  }
  return false;
}

class Solution {
 public:
  bool makesquare(std::vector<int>& matchsticks) {
    auto const n = std::size(matchsticks);
    std::sort(std::begin(matchsticks), std::end(matchsticks), std::greater{});
    auto const sum =
        std::accumulate(std::cbegin(matchsticks), std::cend(matchsticks), 0);
    if (sum % 4 != 0) return false;
    return can_make_square(0, 0, 0, 0, 0, matchsticks, sum / 4);
  }
};
