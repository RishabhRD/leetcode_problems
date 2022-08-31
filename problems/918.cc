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
  int maxSubarraySumCircular(std::vector<int> const& nums) {
    int max_sum_till_now = nums[0];
    int min_sum_till_now = nums[0];
    int cur_max = 0;
    int cur_min = 0;
    int total = 0;
    for (auto num : nums) {
      cur_max = std::max(cur_max + num, num);
      cur_min = std::min(cur_min + num, num);
      max_sum_till_now = std::max(max_sum_till_now, cur_max);
      min_sum_till_now = std::min(min_sum_till_now, cur_min);
      total += num;
    }
    if (max_sum_till_now > 0)
      return std::max(total - min_sum_till_now, max_sum_till_now);
    else
      return max_sum_till_now;
  }
};
