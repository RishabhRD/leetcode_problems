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
  int trap(std::vector<int>& nums) {
    ll left = 0;
    ll right = nums.size() - 1;
    ll max_left = nums[0];
    ll max_right = nums.back();
    ll sum = 0;
    while (left <= right) {
      if (max_left < max_right) {
        max_left = std::max<ll>(max_left, nums[left]);
        sum += max_left - nums[left];
        ++left;
      } else {
        max_right = std::max<ll>(max_right, nums[right]);
        sum += max_right - nums[right];
        --right;
      }
    }
    return sum;
  }
};
