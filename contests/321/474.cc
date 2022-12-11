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

/*
 * ["10","10", "0001","111001","1","0"]
 *
 * m: 5
 * n: 3
 *
 * m: 5
 * n: 3
 *
 * m: 2
 * n: 2
 *
 * m: 2
 * n: 1 0
 *
 */

ll dfs(ll i, ll cur_m, ll cur_n, std::vector<ll> const& num_one,
       std::vector<ll> const& num_zero,
       std::vector<std::vector<std::vector<ll>>>& dp) {
  if (i >= std::size(num_one)) {
    return 0;
  }
  if (dp[i][cur_m][cur_n] != -1) return dp[i][cur_m][cur_n];
  ll ans = 0;
  ans = std::max(ans, dfs(i + 1, cur_m, cur_n, num_one, num_zero, dp));
  if (num_one[i] <= cur_n && num_zero[i] <= cur_m) {
    ans = std::max(ans, 1 + dfs(i + 1, cur_m - num_zero[i], cur_n - num_one[i],
                                num_one, num_zero, dp));
  }
  return dp[i][cur_m][cur_n] = ans;
}

class Solution {
 public:
  int findMaxForm(std::vector<std::string>& strs, int m, int n) {
    auto const size = std::size(strs);
    std::vector dp(size, std::vector(m + 1, std::vector(n + 1, -1ll)));
    std::vector<ll> num_one;
    std::vector<ll> num_zero;
    for (auto const& s : strs) {
      ll one_count = 0;
      ll z_count = 0;
      for (auto e : s) {
        if (e == '0')
          ++z_count;
        else
          ++one_count;
      }
      num_zero.push_back(z_count);
      num_one.push_back(one_count);
    }
    return dfs(0, m, n, num_one, num_zero, dp);
  }
};
