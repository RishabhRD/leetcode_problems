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
  int maxSum(std::vector<std::vector<int>> const& grid) {
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    int sum = 0;
    for (int i = 0; i + 2 < m; ++i) {
      for (int j = 0; j + 2 < n; ++j) {
        sum = std::max(sum, grid[i][j] + grid[i][j + 1] + grid[i][j + 2] +
                                grid[i + 1][j + 1] + grid[i + 2][j] +
                                grid[i + 2][j + 1] + grid[i + 2][j + 2]);
      }
    }
    return sum;
  }
};
