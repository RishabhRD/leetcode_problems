#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

constexpr auto num_greater_equal(int n){
  return 5 - n;
}

auto count_valid(int len, int prev_val, std::vector<vector<optional<int>>>& dp) {
  if(len == 1) return num_greater_equal(prev_val);
  if(dp[prev_val][len]) return dp[prev_val][len].value();
  auto num_valid = 0;
  for(int i = 0; i < num_greater_equal(prev_val); ++i){
    num_valid += count_valid(len - 1, prev_val + i, dp);
  }
  dp[prev_val][len] = num_valid;
  return num_valid;
}

class Solution {
public:
    int countVowelStrings(int n) {
      std::vector dp(5, std::vector(n + 1, std::optional<int>{}));
      return count_valid(n, 0, dp);
    }
};
