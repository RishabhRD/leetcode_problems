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

template <typename Predicate>
ll binary_search(ll low, ll high, Predicate&& predicate) {
  if (low >= high) return low;
  auto const mid = low + (high - low) / 2;
  if (predicate(mid)) {
    return binary_search(mid + 1, high, predicate);
  } else {
    return binary_search(low, mid, predicate);
  }
}

class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    auto is_rotation_point = [&](ll i) { return nums[i] > nums.back(); };
    auto is_less_than_target = [&](ll i) { return nums[i] < target; };
    auto const rotation_point =
        binary_search(0, nums.size(), is_rotation_point);
    auto const left_ans = binary_search(0, rotation_point, is_less_than_target);
    auto const right_ans =
        binary_search(rotation_point, nums.size(), is_less_than_target);
    if (left_ans != rotation_point && nums[left_ans] == target)
      return left_ans;
    else if (right_ans != nums.size() && nums[right_ans] == target)
      return right_ans;
    else
      return -1;
  }
};
