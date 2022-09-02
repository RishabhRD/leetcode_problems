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

int max_uncorssed(std::vector<int> const& nums1, std::vector<int> const& nums2,
                  int nums1_idx, int nums2_idx,
                  std::vector<std::vector<int>>& dp) {
  if (nums1_idx >= std::size(nums1)) return 0;
  if (nums2_idx >= std::size(nums2)) return 0;

  if (dp[nums1_idx][nums2_idx] != -1) return dp[nums1_idx][nums2_idx];

  if (nums1[nums1_idx] == nums2[nums2_idx])
    return dp[nums1_idx][nums2_idx] =
               1 +
               max_uncorssed(nums1, nums2, nums1_idx + 1, nums2_idx + 1, dp);
  else
    return dp[nums1_idx][nums2_idx] = std::max(
               max_uncorssed(nums1, nums2, nums1_idx, nums2_idx + 1, dp),
               max_uncorssed(nums1, nums2, nums1_idx + 1, nums2_idx, dp));
}

class Solution {
 public:
  int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
    auto const n1 = std::size(nums1);
    auto const n2 = std::size(nums2);
    std::vector dp(n1, std::vector(n2, -1));
    return max_uncorssed(nums1, nums2, 0, 0, dp);
  }
};
