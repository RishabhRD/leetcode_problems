#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int subarraySum(std::vector<int>& nums, int k) {
    auto const n = std::size(nums);
    int cnt = 0;
    int cur_sum = 0;
    std::unordered_map<int, int> prefix_sums{{0, 1}};
    // folding with partial sum range in map and exculsive_scan with number
    for (int num : nums) {
      cur_sum += num;
      auto const prefix_sum_wanted = cur_sum - k;
      if (prefix_sums.find(prefix_sum_wanted) != prefix_sums.end()) {
        cnt += prefix_sums[prefix_sum_wanted];
      }
      ++prefix_sums[cur_sum];
    }
    return cnt;
  }
};
