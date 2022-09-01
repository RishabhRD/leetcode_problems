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
  int longestArithSeqLength(std::vector<int>& nums) {
    auto const n = std::size(nums);
    std::vector dp(n, std::vector(n, 2));
    std::unordered_map<int, int> mp{};
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }

    int max_ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        auto const first_ele = nums[i];
        auto const second_ele = nums[j];
        auto const d = second_ele - first_ele;
        auto const prev_ele = first_ele - d;
        if (mp.find(prev_ele) != mp.end()) {
          auto prev_ele_idx = mp[prev_ele];
          dp[i][j] = 1 + dp[prev_ele_idx][i];
        }
        max_ans = std::max(max_ans, dp[i][j]);
      }
      mp[nums[i]] = i;
    }
    return max_ans;
  }
};
