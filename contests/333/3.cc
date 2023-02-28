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

ll constexpr mod = 1e9 + 7;

ll dfs(ll i, ll prev, std::vector<ll> const& nums,
       std::vector<std::vector<ll>> const& prime_factors,
       std::vector<std::vector<ll>>& dp) {
  if (i >= nums.size()) return prev != 0;
  if (dp[i][prev] != -1) return dp[i][prev];
  ll ans = 0;
  ans = (ans + dfs(i + 1, prev, nums, prime_factors, dp)) % mod;
  std::bitset<11> bs(prev);
  if (nums[i] == 1) {
    bs[0] = true;
    ans = (ans + dfs(i + 1, bs.to_ullong(), nums, prime_factors, dp)) % mod;
  } else {
    bool found = false;
    for (auto n : prime_factors[nums[i]]) {
      if (bs[n]) {
        found = true;
        break;
      } else {
        bs[n] = true;
      }
    }
    if (!found) {
      ans = (ans + dfs(i + 1, bs.to_ullong(), nums, prime_factors, dp)) % mod;
    }
  }
  return dp[i][prev] = ans;
}

class Solution {
 public:
  int squareFreeSubsets(std::vector<int>& nums) {
    std::vector<std::vector<ll>> prime_factors(31);
    std::unordered_map<ll, ll> mapping{{1, 0},  {2, 1},  {3, 2},  {5, 3},
                                       {7, 4},  {11, 5}, {13, 6}, {17, 7},
                                       {19, 8}, {23, 9}, {29, 10}};
    for (ll i = 2; i <= 30; ++i) {
      ll cur = i;
      for (ll j = 2; j <= i; ++j) {
        if (cur % j == 0) {
          prime_factors[i].push_back(j);
        }
        while (cur % j == 0) cur /= j;
      }
      for (auto& n : prime_factors[i]) n = mapping[n];
    }

    std::unordered_set<ll> forbidden{4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28};
    std::vector<ll> nnums;
    for (auto n : nums) {
      if (!forbidden.count(n)) {
        nnums.push_back(n);
      }
    }
    ll const n = nnums.size();
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(2049, -1));
    return dfs(0, 0, nnums, prime_factors, dp);
  }
};
