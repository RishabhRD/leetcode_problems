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

int count_extrema(std::vector<int> const& nums) {
  auto const n = std::size(nums);
  int num_extrema_till_peak = 1;
  int num_extrema_till_valley = 1;
  for (std::size_t i{1}; i < n; ++i) {
    if (nums[i] > nums[i - 1]) {
      num_extrema_till_peak = num_extrema_till_valley + 1;
    } else if (nums[i] < nums[i - 1]) {
      num_extrema_till_valley = num_extrema_till_peak + 1;
    }
  }
  return std::max(num_extrema_till_peak, num_extrema_till_valley);
}

class Solution {
 public:
  int wiggleMaxLength(std::vector<int>& nums) { return count_extrema(nums); }
};
