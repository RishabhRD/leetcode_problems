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
  double findMaxAverage(std::vector<int>& nums, int k) {
    int low = 0;
    double cur_sum = 0;
    double max_sum = INT32_MIN;
    for (int high = 0; high < std::size(nums); ++high) {
      cur_sum += nums[high];
      while (high - low + 1 > k) {
        cur_sum -= nums[low];
        ++low;
      }
      if (high - low + 1 == k) {
        max_sum = std::max(max_sum, cur_sum);
      }
    }
    return max_sum / k;
  }
};
