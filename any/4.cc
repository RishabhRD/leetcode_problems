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

double left(vector<int> const &arr, int left_num_ele) {
  if (left_num_ele == 0) return INT32_MIN;
  return arr[left_num_ele - 1];
}

double right(vector<int> const &arr, int left_num_ele) {
  if (left_num_ele == size(arr)) return INT32_MAX;
  return arr[left_num_ele];
}

class Solution {
public:
  double findMedianSortedArrays(vector<int> const &nums1,
    vector<int> const &nums2) {
    if (size(nums2) < size(nums1)) return findMedianSortedArrays(nums2, nums1);
    int const n1 = size(nums1);
    int const n2 = size(nums2);
    int const partition_size = (n1 + n2 + 1) / 2;
    int low = 0;
    int high = n1;
    while (low <= high) {
      int const left_num_ele_1 = (low + high) / 2;
      int const left_num_ele_2 = partition_size - left_num_ele_1;
      auto const l1 = left(nums1, left_num_ele_1);
      auto const l2 = left(nums2, left_num_ele_2);
      auto const r1 = right(nums1, left_num_ele_1);
      auto const r2 = right(nums2, left_num_ele_2);
      if (l1 <= r2 and l2 <= r1) {
        if ((n1 + n2) % 2 == 0) {
          return (max(l1, l2) + min(r1, r2)) / 2;
        } else {
          return max(l1, l2);
        }
      } else if (l1 > r2) {
        high = left_num_ele_1 - 1;
      } else if (l2 > r1) {
        low = left_num_ele_1 + 1;
      }
    }
    return -1;
  }
};

/* int main(){ */
/*   Solution sol; */
/*   cout << sol.findMedianSortedArrays({1, 3}, {2}) << endl; */
/* } */
