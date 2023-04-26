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
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    if (nums1.size() > nums2.size())
      return findMedianSortedArrays(nums2, nums1);

    auto const n1 = nums1.size();
    auto const n2 = nums2.size();

    auto const n = (n1 + n2) / 2;

    auto is_good = [&](auto m1) {
      auto const m2 = n - m1;
      auto const left_max = std::max((m1 == 0) ? INT32_MIN : nums1[m1 - 1],
                                     (m2 == 0) ? INT32_MIN : nums2[m2 - 1]);
      auto const right = m1 == n1 ? INT32_MAX : nums1[m1];
      return left_max > right;
    };

    auto const l = binary_search(0ll, std::min(n, n1) + 1, is_good);
    auto const r = n - l;
    if ((n1 + n2) % 2) {
      return std::min(l == n1 ? INT32_MAX : nums1[l],
                      r == n2 ? INT32_MAX : nums2[r]);
    } else {
      auto const left = std::max(l == 0 ? INT32_MIN : nums1[l - 1],
                                 r == 0 ? INT32_MIN : nums2[r - 1]);
      auto const right = std::min(l == n1 ? INT32_MAX : nums1[l],
                                  r == n2 ? INT32_MAX : nums2[r]);
      return (left + right) / 2.0;
    }
  }
};
