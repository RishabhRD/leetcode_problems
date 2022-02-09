#include <optional>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

constexpr long left(vector<int> const &nums, int left_ele) {
  return (left_ele - 1 >= 0) ? nums[left_ele - 1] : INT32_MIN;
}

constexpr long right(vector<int> const &nums, int left_ele) {
  return (left_ele < size(nums)) ? nums[left_ele] : INT32_MAX;
}

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int const n1 = size(nums1);
    int const n2 = size(nums2);
    if (n2 < n1) return findMedianSortedArrays(nums2, nums1);
    int const n = n1 + n2;
    int const total_ele_left = (n + 1) / 2;
    int const total_ele_right = n - total_ele_left;
    int low_nums1_left = 0;
    int high_nums1_left = min(total_ele_left, n1);
    while (low_nums1_left <= high_nums1_left) {
      int const nums1_left = (low_nums1_left + high_nums1_left) / 2;
      int const nums2_left = total_ele_left - nums1_left;
      auto const l1 = left(nums1, nums1_left);
      auto const l2 = left(nums2, nums2_left);
      auto const r1 = right(nums1, nums1_left);
      auto const r2 = right(nums2, nums2_left);
      if (l1 <= r2 and l2 <= r1) {
        if (n % 2 == 0) {
          return (max(l1, l2) + min(r1, r2)) / 2.0;
        } else {
          return max(l1, l2);
        }
      } else if (l1 > r2) {
        high_nums1_left = nums1_left - 1;
      } else {
        low_nums1_left = nums1_left + 1;
      }
    }
    return 0.0;
  }
};
