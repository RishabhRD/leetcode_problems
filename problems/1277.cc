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
  int countSquares(std::vector<std::vector<int>> const& matrix) {
    auto const m = std::size(matrix);
    auto const n = std::size(matrix[0]);
    auto const max_len = std::min(m, n);
    std::vector dp(m, std::vector(n, 0));
    auto ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 1) {
          auto left = (j - 1) >= 0 ? dp[i][j - 1] : 0;
          auto up = (i - 1) >= 0 ? dp[i - 1][j] : 0;
          auto up_left = ((i - 1) >= 0 and (j - 1) >= 0) ? dp[i - 1][j - 1] : 0;
          dp[i][j] = std::min({left, up, up_left}) + 1;
          ans += dp[i][j];
        }
      }
    }
    return ans;
  }
};
