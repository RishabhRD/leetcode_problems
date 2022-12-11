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

using ll = long long;

class Solution {
 public:
  int deleteGreatestValue(std::vector<std::vector<int>>& grid) {
    for (auto& vec : grid)
      std::sort(std::begin(vec), std::end(vec), std::greater<>());
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    ll sum = 0;
    for (ll j = 0; j < n; ++j) {
      ll max = grid[0][j];
      for (ll i = 1; i < m; ++i) max = std::max<ll>(max, grid[i][j]);
      sum += max;
    }
    return sum;
  }
};
