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
  int matchPlayersAndTrainers(std::vector<int>& players,
                              std::vector<int>& trainers) {
    std::sort(std::begin(players), std::end(players));
    std::sort(std::begin(trainers), std::end(trainers));

    int ans = 0;
    int i = 0;
    int j = 0;

    auto const m = std::size(players);
    auto const n = std::size(trainers);

    while (i < m and j < n) {
      if (players[i] <= trainers[j]) {
        ++i;
        ++j;
        ++ans;
      } else {
        ++j;
      }
    }
    return ans;
  }
};
