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

ll dfs(ll i, ll k, std::vector<int> const& nums, std::vector<ll>& dp) {
  if (i >= nums.size()) return 0;
  if (dp[i] != -1) return dp[i];
  std::vector<ll> visited(1000, 0);
  ll sum = 0;
  ll ans = INT32_MAX;
  for (ll j = i; j < nums.size(); ++j) {
    ++visited[nums[j]];
    if (visited[nums[j]] == 2) {
      sum += 2;
    } else if (visited[nums[j]] > 2) {
      sum += 1;
    }
    ans = std::min(ans, sum + k + dfs(j + 1, k, nums, dp));
  }
  return dp[i] = ans;
}

class Solution {
 public:
  int minCost(std::vector<int>& nums, int k) {
    ll const n = nums.size();
    std::vector<ll> dp(n, -1);
    ll ans = dfs(0, k, nums, dp);
    return ans;
  }
};
