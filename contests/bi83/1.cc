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

class Solution {
 public:
  std::string bestHand(std::vector<int>& ranks, std::vector<char>& suits) {
    auto const is_flush =
        std::all_of(std::cbegin(suits), std::cend(suits),
                    [&](auto ele) { return ele == suits[0]; });
    std::unordered_map<int, int> mp;
    for (auto ele : ranks) ++mp[ele];
    auto max = 0;
    for (auto [k, v] : mp) max = std::max(max, v);
    if (is_flush)
      return "Flush";
    else if (max >= 3)
      return "Three of a Kind";
    else if (max == 2)
      return "Pair";
    else
      return "High Card";
  }
};
