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
  int shortestSubarray(std::vector<int>& nums, int k) {
    int min_ans = INT32_MAX;
    int low = 0;
    int cur_sum = 0;
    for (int high = 0; high < std::size(nums); ++high) {
      cur_sum += nums[high];
      while (low <= high and cur_sum >= k) {
        min_ans = std::min(min_ans, high - low + 1);
        cur_sum -= nums[low];
        ++low;
      }
    }
    return min_ans == INT32_MAX ? -1 : min_ans;
  }
};
