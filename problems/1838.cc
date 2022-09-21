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
  int maxFrequency(std::vector<int>& nums, int k) {
    std::sort(std::begin(nums), std::end(nums));
    long long low = 0;
    long long ans = 0;
    long long cur_sum = 0;
    for (long long high = 0; high < std::size(nums); ++high) {
      cur_sum += nums[high];
      while ((high - low + 1) * nums[high] > cur_sum + k) {
        cur_sum -= nums[low];
        ++low;
      }
      ans = std::max(ans, high - low + 1);
    }
    return ans;
  }
};
