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

ll merge(int low, int mid, int high, std::vector<int>& nums, int d) {
  int i = low;
  int j = mid + 1;
  ll count = 0;
  while (i <= mid and j <= high) {
    if (nums[i] <= nums[j] + d) {
      count += high - j + 1;
      ++i;
    } else {
      ++j;
    }
  }
  std::sort(std::begin(nums) + low, std::begin(nums) + high + 1);
  // O(n) merge is slower in practice
  // std::vector<int> temp(high - low + 1);
  // std::merge(std::begin(nums) + low, std::begin(nums) + mid + 1,
  //            std::begin(nums) + mid + 1, std::begin(nums) + high + 1,
  //            std::begin(temp));
  // std::copy(std::begin(temp), std::end(temp), std::begin(nums) + low);
  return count;
}

ll merge_sort(int low, int high, std::vector<int>& nums, int d) {
  if (low >= high) return 0;
  auto const mid = (low + high) / 2;
  auto const left = merge_sort(low, mid, nums, d);
  auto const right = merge_sort(mid + 1, high, nums, d);
  auto const merger = merge(low, mid, high, nums, d);
  return left + right + merger;
}

class Solution {
 public:
  long long numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2,
                          int diff) {
    auto const n = std::size(nums1);
    std::vector nums(n, 0);
    for (int i = 0; i < n; ++i) {
      nums[i] = nums1[i] - nums2[i];
    }

    return merge_sort(0, n - 1, nums, diff);
  }
};
