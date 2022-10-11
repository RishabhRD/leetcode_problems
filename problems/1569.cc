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

int dp[1001][1001] = {};
int comb(int n, int m) {
  return n == 0 || m == 0 ? 1
         : dp[n][m]       ? dp[n][m]
                    : dp[n][m] = (comb(n - 1, m) + comb(n, m - 1)) % 1000000007;
}

ll num_ways(std::vector<int> const& nums) {
  constexpr static int mod = 1e9 + 7;
  if (nums.size() <= 2) return 1;
  std::vector<int> left;
  std::vector<int> right;
  std::copy_if(std::cbegin(nums), std::cend(nums), std::back_inserter(left),
               [&](auto ele) { return ele < nums[0]; });
  std::copy_if(std::cbegin(nums), std::cend(nums), std::back_inserter(right),
               [&](auto ele) { return ele > nums[0]; });
  auto const left_ans = num_ways(left);
  auto const right_ans = num_ways(right);
  auto const m = left.size();
  auto const n = right.size();
  return left_ans * right_ans % mod * comb(m, n) % mod;
}

class Solution {
 public:
  int numOfWays(std::vector<int>& nums) {
    auto const n = std::size(nums);
    return num_ways(nums) - 1;
  }
};
