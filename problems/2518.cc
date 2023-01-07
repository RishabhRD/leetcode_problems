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

constexpr ll mod = 1e9 + 7;

class Solution {
 public:
  int countPartitions(std::vector<int>& nums, int k) {
    auto const n = std::size(nums);
    auto const sum = std::reduce(std::begin(nums), std::end(nums), 0ll);
    if (k * 2 > sum) return 0;
    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(k, 0));
    for (ll i = 0; i <= n; ++i) {
      dp[i][0] = 1;
    }
    for (ll i = 1; i <= n; ++i) {
      for (ll j = 1; j < k; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j - nums[i - 1] >= 0) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - nums[i - 1]]) % mod;
        }
      }
    }
    ll ans = 0;
    for (ll i = 0; i < k; ++i) {
      ans = (ans + dp[n][i]) % mod;
    }
    ans = (ans * 2) % mod;
    ll total = 2;
    for (ll i = 1; i < n; ++i) {
      total = (total * 2) % mod;
    }
    return (total - ans + mod) % mod;
  }
};
