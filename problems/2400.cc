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

constexpr int mod = 1e9 + 7;

int num_ways(int start_pos, int end_pos, int k,
             std::vector<std::vector<int>>& dp) {
  if (end_pos - start_pos > k) return 0;
  if (k == 0) {
    if (start_pos == end_pos)
      return 1;
    else
      return 0;
  }

  if (dp[start_pos + 1000][k + 1000] != -1) {
    return dp[start_pos + 1000][k + 1000];
  }

  return dp[start_pos + 1000][k + 1000] =
             (num_ways(start_pos - 1, end_pos, k - 1, dp) % mod +
              num_ways(start_pos + 1, end_pos, k - 1, dp) % mod) %
             mod;
}

class Solution {
 public:
  int numberOfWays(int startPos, int endPos, int k) {
    std::vector dp(4002, std::vector(4002, -1));
    return num_ways(startPos, endPos, k, dp);
  }
};
