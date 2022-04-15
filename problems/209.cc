#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int> const &nums) {
    size_t i = 0;
    auto const n = size(nums);
    auto sum = 0;
    auto min_len = n + 1;
    for (size_t j = 0; j < n; ++j) {
      sum += nums[j];
      while (sum >= target) {
        if (j - i + 1 < min_len) {
          min_len = j - i + 1;
        }
        sum -= nums[i];
        ++i;
      }
    }
    return min_len == n + 1 ? 0 : min_len;
  }
};
