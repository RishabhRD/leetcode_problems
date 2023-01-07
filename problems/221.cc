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
  int maximalSquare(std::vector<std::vector<char>>& matrix) {
    auto const m = std::size(matrix);
    auto const n = std::size(matrix[0]);
    std::vector dp(m, std::vector(n, 0ll));
    ll ans = 0;
    for (ll i = 0; i < m; ++i) {
      if (matrix[i][0] == '1') {
        dp[i][0] = 1;
        ans = 1;
      }
    }
    for (ll j = 0; j < n; ++j) {
      if (matrix[0][j] == '1') {
        dp[0][j] = 1;
        ans = 1;
      }
    }
    for (ll i = 1; i < m; ++i) {
      for (ll j = 1; j < n; ++j) {
        if (matrix[i][j] == '0') continue;
        auto const len = std::min(dp[i - 1][j], dp[i][j - 1]);
        if (matrix[i - len][j - len] == '1') {
          dp[i][j] = len + 1;
        } else {
          dp[i][j] = len;
        }
        ans = std::max(ans, dp[i][j]);
      }
    }
    return ans * ans;
  }
};
