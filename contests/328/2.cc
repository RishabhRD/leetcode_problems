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
  std::vector<std::vector<int>> rangeAddQueries(
      int n, std::vector<std::vector<int>>& queries) {
    std::vector matrix(n, std::vector(n, 0));
    for (auto const& query : queries) {
      auto const x1 = query[0];
      auto const y1 = query[1];
      auto const x2 = query[2];
      auto const y2 = query[3];
      for (ll i = x1; i <= x2; ++i) {
        ++matrix[i][y1];
      }
      if (y2 + 1 < n) {
        for (ll i = x1; i <= x2; ++i) {
          --matrix[i][y2 + 1];
        }
      }
    }
    for (auto& row : matrix) {
      for (ll i = 1; i < n; ++i) {
        row[i] = row[i] + row[i - 1];
      }
    }
    return matrix;
  }
};
