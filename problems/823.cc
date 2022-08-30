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
  int numFactoredBinaryTrees(std::vector<int>& arr) {
    auto const n = std::size(arr);
    std::sort(std::begin(arr), std::end(arr));
    std::unordered_map<int, ll> dp;

    for (int i = 0; i < n; ++i) {
      dp[arr[i]] = 1;
      for (int j = 0; j < i; ++j) {
        if (arr[i] % arr[j] == 0) {
          dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % mod;
        }
      }
    }

    ll sum = 0;
    for (auto [k, v] : dp) {
      sum = (sum + v) % mod;
    }
    return sum;
  }
};
