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

using ll = long long;

class Solution {
 public:
  int maxNumOfMarkedIndices(std::vector<int>& nums) {
    if (nums.size() == 1) return 0;
    std::sort(std::begin(nums), std::end(nums));
    ll const n = nums.size();
    ll left_low = 0;
    ll left_high = n / 2 - 1;
    ll right_low = n / 2;
    if (n % 2) ++right_low;
    ll right_high = n - 1;
    ll sum = 0;
    while (left_low <= left_high && right_low <= right_high) {
      if (2 * nums[left_low] <= nums[right_low]) {
        sum += 2;
        ++left_low;
        ++right_low;
      } else {
        ++right_low;
      }
    }
    return sum;
  }
};
