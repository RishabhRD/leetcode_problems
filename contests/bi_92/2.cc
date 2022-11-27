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
  std::vector<std::vector<int>> onesMinusZeros(
      std::vector<std::vector<int>>& grid) {
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    std::vector<ll> ones_row(m);
    std::vector<ll> zeros_row(m);
    for (int i = 0; i < m; ++i) {
      int num_zeros = 0;
      int num_ones = 0;
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) ++num_zeros;
        if (grid[i][j] == 1) ++num_ones;
      }
      ones_row[i] = num_ones;
      zeros_row[i] = num_zeros;
    }
    std::vector<ll> ones_col(n);
    std::vector<ll> zeros_col(n);
    for (int j = 0; j < n; ++j) {
      int num_zeros = 0;
      int num_ones = 0;
      for (int i = 0; i < m; ++i) {
        if (grid[i][j] == 0) ++num_zeros;
        if (grid[i][j] == 1) ++num_ones;
      }
      ones_col[j] = num_ones;
      zeros_col[j] = num_zeros;
    }
    std::vector diff(m, std::vector(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        diff[i][j] = ones_row[i] + ones_col[j] - zeros_row[i] - zeros_col[j];
      }
    }
    return diff;
  }
};
