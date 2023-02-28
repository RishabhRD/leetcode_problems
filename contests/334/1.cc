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

class Solution {
 public:
  std::vector<int> leftRigthDifference(std::vector<int>& nums) {
    ll const n = nums.size();
    std::vector<ll> left_sum(n);
    left_sum[0] = 0;
    for (ll i = 1; i < n; ++i) {
      left_sum[i] = left_sum[i - 1] + nums[i - 1];
    }

    std::vector<ll> right_sum(n);
    right_sum[n - 1] = 0;
    for (ll i = n - 2; i >= 0; --i) {
      right_sum[i] = right_sum[i + 1] + nums[i + 1];
    }

    std::vector<int> res(n);
    for (ll i = 0; i < n; ++i) {
      res[i] = std::abs(left_sum[i] - right_sum[i]);
    }

    return res;
  }
};
