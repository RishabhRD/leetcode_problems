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
  int fillCups(std::vector<int>& amount) {
    int steps = 0;
    while (!std::all_of(std::begin(amount), std::end(amount),
                        [](auto ele) { return ele == 0; })) {
      std::sort(std::begin(amount), std::end(amount), std::greater{});
      if (amount[0] > 0) --amount[0];
      if (amount[1] > 0) --amount[1];
      ++steps;
    }
    return steps;
  }
};
