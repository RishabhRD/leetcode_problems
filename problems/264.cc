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

int nth_ugly_number(int const n) {
  std::vector dp(n, 1ll);
  int two_ptr = 0, three_ptr = 0, five_ptr = 0;
  for (size_t i = 1; i < n; ++i) {
    auto const two_res = dp[two_ptr] * 2;
    auto const three_res = dp[three_ptr] * 3;
    auto const five_res = dp[five_ptr] * 5;
    dp[i] = std::min({two_res, three_res, five_res});
    if (dp[i] == two_res) ++two_ptr;
    if (dp[i] == three_res) ++three_ptr;
    if (dp[i] == five_res) ++five_ptr;
  }
  return dp[n - 1];
}

class Solution {
 public:
  int nthUglyNumber(int n) { return nth_ugly_number(n); }
};
