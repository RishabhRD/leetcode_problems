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

ll min_steps(ll cur_char, ll cur_copied, ll n,
             std::vector<std::vector<ll>>& dp) {
  if (cur_char == n) return 0;
  if (cur_char > n) return 2 * n;
  if (dp[cur_char][cur_copied] != -1) return dp[cur_char][cur_copied];
  if (cur_copied != cur_char) {
    return dp[cur_char][cur_copied] =
               1 +
               std::min(min_steps(cur_char, cur_char, n, dp),
                        min_steps(cur_char + cur_copied, cur_copied, n, dp));
  } else {
    return dp[cur_char][cur_copied] =
               1 + min_steps(cur_char + cur_copied, cur_copied, n, dp);
  }
}

class Solution {
 public:
  int minSteps(int n) {
    if (n == 1) return 0;
    std::vector dp(n + 1, std::vector(n + 1, -1ll));
    return 1 + min_steps(1, 1, n, dp);
  }
};
