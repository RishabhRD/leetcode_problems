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
  int lenLongestFibSubseq(std::vector<int>& arr) {
    auto const n = std::size(arr);
    std::unordered_map<int, int> idx_map;
    for (int i = 0; i < n; ++i) {
      idx_map[arr[i]] = i;
    }
    std::vector dp(n, std::vector(n, 1));
    auto res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        auto const prev_value = arr[j] - arr[i];
        auto const prev_value_idx_itr = idx_map.find(prev_value);
        if (prev_value_idx_itr == idx_map.end()) {
          dp[i][j] = 2;
          continue;
        }
        auto const k = prev_value_idx_itr->second;
        dp[i][j] = 1 + dp[k][i];
        res = std::max(res, dp[i][j]);
      }
    }
    return res < 3 ? 0 : res;
  }
};
