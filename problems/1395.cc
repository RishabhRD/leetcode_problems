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
  int numTeams(std::vector<int> const& rating) {
    auto const n = std::size(rating);
    auto ans = 0;
    for (int i = 0; i < n; ++i) {
      auto const cur = rating[i];

      auto left_smaller = 0;
      auto left_larger = 0;
      for (int j = 0; j < i; ++j) {
        if (rating[j] < cur)
          ++left_smaller;
        else if (rating[j] > cur)
          ++left_larger;
      }

      auto right_smaller = 0;
      auto right_larger = 0;
      for (int j = i + 1; j < n; ++j) {
        if (rating[j] < cur)
          ++right_smaller;
        else if (rating[j] > cur)
          ++right_larger;
      }

      ans += left_larger * right_smaller + left_smaller * right_larger;
    }
    return ans;
  }
};
