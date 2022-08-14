#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int nth_ugly_number(std::size_t const n, vector<int> const& primes) {
  auto const primes_size = std::size(primes);
  std::vector<std::size_t> primes_idx(primes_size, 0);
  std::vector<long long> dp(n, INT64_MAX);
  dp[0] = 1;
  for (std::size_t i{1}; i < n; ++i) {
    for (std::size_t j{0}; j < primes_size; ++j) {
      dp[i] = std::min(dp[i],
                       static_cast<long long>(primes[j] * dp[primes_idx[j]]));
    }
    for (std::size_t j{0}; j < primes_size; ++j) {
      if (dp[i] == primes[j] * dp[primes_idx[j]]) ++primes_idx[j];
    }
  }
  return dp[n - 1];
}

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    return nth_ugly_number(n, primes);
  }
};
