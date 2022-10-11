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

class Solution {
 public:
  int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {
    auto const x1 = std::accumulate(std::begin(nums1), std::end(nums1), 0,
                                    std::bit_xor<int>{});
    auto const x2 = std::accumulate(std::begin(nums2), std::end(nums2), 0,
                                    std::bit_xor<int>{});

    auto ans = 0;
    if (nums2.size() % 2 == 1) ans ^= x1;
    if (nums1.size() % 2 == 1) ans ^= x2;
    return ans;
  }
};
