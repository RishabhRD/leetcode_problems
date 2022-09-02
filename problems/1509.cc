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
  int minDifference(std::vector<int> &nums) {
    std::sort(std::begin(nums), std::end(nums));
    if (nums.size() <= 3)
      return 0;
    auto const n = std::size(nums);
    return std::min({
        nums[n - 4] - nums[0],
        nums[n - 3] - nums[1],
        nums[n - 2] - nums[2],
        nums[n - 1] - nums[3],
    });
  }
};
