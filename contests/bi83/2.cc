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
  long long zeroFilledSubarray(std::vector<int> const& nums) {
    long long sum = 0;
    long long cur = 0;
    long long prev = -1;
    for (int i = 0; i < std::size(nums); ++i) {
      if (nums[i] == 0) {
        if (prev == 0)
          ++cur;
        else
          cur = 1;
      } else {
        cur = 0;
      }
      sum += cur;
      prev = nums[i];
    }
    return sum;
  }
};
