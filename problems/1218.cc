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
  int longestSubsequence(std::vector<int>& arr, int difference) {
    auto const n = std::size(arr);
    std::vector dp(n, 1);
    std::unordered_map<int, int> mp;
    auto ans = 0;
    for (int i = 0; i < n; ++i) {
      auto const req_ele = arr[i] - difference;
      if (mp.find(req_ele) != mp.end()) {
        dp[i] = std::max(dp[i], 1 + dp[mp[req_ele]]);
      }
      ans = std::max(ans, dp[i]);
      mp[arr[i]] = i;
    }
    return ans;
  }
};
