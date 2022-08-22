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

class Solution {
 public:
  int deleteAndEarn(std::vector<int>& nums) {
    constexpr std::size_t const arr_size = 1e4 + 1;
    std::array<int, arr_size> freq{0};
    for (auto num : nums) {
      ++freq[num];
    }
    std::array<int, arr_size> dp{0};
    dp[1] = freq[1];
    for (int i = 2; i < arr_size; ++i) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + freq[i] * i);
    }
    return dp[arr_size - 1];
  }
};
