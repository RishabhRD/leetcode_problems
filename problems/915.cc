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
  int partitionDisjoint(std::vector<int>& nums) {
    auto const n = nums.size();
    std::vector<int> right_minimum(n);
    right_minimum[n - 1] = nums.back();
    for (ll i = n - 2; i >= 0; --i) {
      right_minimum[i] = std::min(nums[i], right_minimum[i + 1]);
    }
    int cur_max = nums[0];
    for (ll i = 0; i < n - 1; ++i) {
      cur_max = std::max(cur_max, nums[i]);
      if (cur_max <= right_minimum[i + 1]) {
        return i + 1;
      }
    }
    return 0;
  }
};
