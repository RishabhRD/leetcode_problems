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

ll dfs(ll i, ll cur_sum, std::vector<std::vector<int>> const& matrix, ll target,
       std::vector<std::vector<ll>>& dp) {
  if (i >= matrix.size()) {
    return std::abs(cur_sum - target);
  }
  if (dp[i][cur_sum] != -1) return dp[i][cur_sum];
  ll ans = INT32_MAX;
  for (ll j = 0; j < matrix[0].size(); ++j) {
    ans = std::min(ans, dfs(i + 1, cur_sum + matrix[i][j], matrix, target, dp));
  }
  return dp[i][cur_sum] = ans;
}

class Solution {
 public:
  int minimizeTheDifference(std::vector<std::vector<int>>& mat, int target) {
    ll const m = mat.size();
    ll const n = mat[0].size();
    std::vector dp(m, std::vector(4901, -1ll));
    return dfs(0, 0, mat, target, dp);
  }
};
