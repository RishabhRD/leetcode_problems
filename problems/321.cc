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

auto merge_vectors(std::vector<int> const& a, std::vector<int> const& b) {
  std::vector<int> res(std::size(a) + std::size(b));
  std::merge(std::cbegin(a), std::cend(a), std::cbegin(b), std::cend(b),
             std::begin(res), std::greater{});
  return res;
}

auto top_k_ele(std::vector<int> const& nums, int k) {
  std::vector<int> res;
  auto const n = std::size(nums);
  for (int i = 0; i < n; ++i) {
    while (not std::empty(res) and res.back() < nums[i] and
           (std::size(res) - 1 + n - i) >= k) {
      res.pop_back();
    }
    if (res.size() < k) res.push_back(nums[i]);
  }
  return res;
}

class Solution {
 public:
  std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2,
                             int k) {
    std::vector<int> cur_max;
    for (int i = 0; i <= k; ++i) {
      if (std::size(nums1) < i || std::size(nums2) < k - i) {
        continue;
      }
      auto const nums1_ele = top_k_ele(nums1, i);
      auto const nums2_ele = top_k_ele(nums2, k - i);
      cur_max = std::max({
          std::move(cur_max),
          merge_vectors(nums1_ele, nums2_ele),
          merge_vectors(nums2_ele, nums1_ele),
      });
    }
    return cur_max;
  }
};
