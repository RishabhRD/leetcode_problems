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

double kth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k){
  const int m = size(nums1);
  const int n = size(nums2);
  if(start1 >= m) return nums2[start2 + k - 1];
  else if(start2 >= n) return nums1[start1 + k - 1];
  else if(k == 1) return min(nums1[start1], nums2[start2]);
  int mid1 = INT32_MAX;
  int mid2 = INT32_MAX;
  if(start1 + k / 2 - 1 < m) mid1 = nums1[start1 + k / 2 - 1];
  if(start2 + k / 2 - 1 < n) mid2 = nums2[start2 + k / 2 - 1];
  if(mid1 < mid2){
    return kth(nums1, start1 + k / 2, nums2, start2, k - k / 2);
  }else{
    return kth(nums1, start1, nums2, start2 + k / 2, k - k / 2);
  }
}

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = size(nums1);
    int n = size(nums2);
    int l = (m + n + 1) / 2;
    int r = (m + n + 2) / 2;
    return (kth(nums1, 0, nums2, 0, l) + kth(nums1, 0, nums2, 0, r)) / 2;
  }
};
