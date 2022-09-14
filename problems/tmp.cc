#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

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
    auto const merged_vector = merge_vectors(nums1, nums2);
    return std::max(top_k_ele(merge_vectors(nums1, nums2), k),
                    top_k_ele(merge_vectors(nums2, nums1), k));
  }
};
