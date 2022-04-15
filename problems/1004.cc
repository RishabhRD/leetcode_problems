#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestOnes(vector<int> &nums, int k) {
    auto const n = size(nums);
    size_t i{};
    size_t max_len{};
    int zero_count = 0;
    for (size_t j{}; j < n; ++j) {
      if (nums[j] == 0) ++zero_count;
      if (zero_count > k) {
        if (nums[i] == 0) --zero_count;
        ++i;
      }
      max_len = max(max_len, j - i + 1);
    }
    return max_len;
  }
};
