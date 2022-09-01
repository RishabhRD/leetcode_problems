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
  int maxScoreSightseeingPair(std::vector<int> const& values) {
    int left_max = values[0];
    int res = 0;
    for (int j = 1; j < std::size(values); ++j) {
      int const right_val = values[j] - j;
      res = std::max(res, left_max + right_val);
      left_max = std::max(left_max, values[j] + j);
    }
    return res;
  }
};
