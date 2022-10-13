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

constexpr static int mod = 1e9 + 7;

int dfs(int n, int cur, std::vector<std::vector<int>> const& factors,
        std::vector<std::vector<int>>& dp) {
  if (n == 1) return 1;
  if (dp[n][cur] >= 0) return dp[n][cur];
  int ans = 0;
  for (auto ele : factors[cur]) {
    ans = (ans + dfs(n - 1, ele, factors, dp)) % mod;
  }
  return dp[n][cur] = ans;
}

class Solution {
 public:
  int idealArrays(int n, int maxValue) {
    std::vector<std::vector<int>> factors(maxValue + 1);
    std::vector dp(n + 1, std::vector(maxValue + 1, -1));
    for (int i = 1; i <= maxValue; ++i) {
      int multiple = 1;
      for (int multiple = 1; i * multiple <= maxValue; ++multiple) {
        factors[i].push_back(i * multiple);
      }
    }
    int res = 0;
    for (int i = 1; i <= maxValue; ++i) {
      res = (res + dfs(n, i, factors, dp)) % mod;
    }
    return res;
  }
};
