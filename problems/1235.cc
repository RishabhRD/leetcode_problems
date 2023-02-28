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

template <typename Predicate>
ll binary_search(ll low, ll high, Predicate&& predicate) {
  if (low >= high) return low;
  auto const mid = low + (high - low) / 2;
  if (predicate(mid)) {
    return binary_search(mid + 1, high, predicate);
  } else {
    return binary_search(low, mid, predicate);
  }
}

ll dfs(ll i, std::vector<std::tuple<ll, ll, ll>> const& jobs,
       std::vector<ll>& dp) {
  if (i == jobs.size()) return 0;
  if (dp[i] != -1) return dp[i];
  auto const next = binary_search(i + 1, jobs.size(), [&](auto idx) {
    return std::get<0>(jobs[idx]) < std::get<1>(jobs[i]);
  });
  return dp[i] = std::max(dfs(i + 1, jobs, dp),
                          std::get<2>(jobs[i]) + dfs(next, jobs, dp));
}

class Solution {
 public:
  int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime,
                    std::vector<int>& profit) {
    ll const n = startTime.size();
    std::vector<std::tuple<ll, ll, ll>> jobs;
    for (ll i = 0; i < n; ++i) {
      jobs.push_back({startTime[i], endTime[i], profit[i]});
    }
    std::sort(std::begin(jobs), std::end(jobs));
    std::vector<ll> dp(n, -1ll);
    return dfs(0, jobs, dp);
  }
};
