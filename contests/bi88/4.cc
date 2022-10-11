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
  long long numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2,
                          int diff) {
    auto const n = std::size(nums1);
    std::vector nums(n, 0);
    for (int i = 0; i < n; ++i) {
      nums[i] = nums1[i] - nums2[i];
    }

    long long ans = 0;
    std::set<int> st;
    for (int n : nums) {
      auto itr = st.upper_bound(n);
      ans += std::distance(std::begin(st), itr);
      st.insert(n - diff);
    }
    return ans;
  }
};
