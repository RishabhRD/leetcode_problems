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
  std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1,
                                               std::vector<int>& nums2, int k) {
    using pii = std::pair<int, int>;
    auto cmp = [&nums2](auto a, auto b) {
      return a.first + nums2[a.second] > b.first + nums2[b.second];
    };
    std::priority_queue<pii, std::vector<pii>, decltype(cmp)> pq(cmp);
    for (auto n : nums1) {
      pq.push({n, 0});
    }

    std::vector<std::vector<int>> res;
    while (not empty(pq) and k--) {
      auto [first_num, second_idx] = pq.top();
      pq.pop();
      res.push_back({first_num, nums2[second_idx]});
      if (second_idx + 1 < std::size(nums2)) {
        pq.push({first_num, second_idx + 1});
      }
    }
    return res;
  }
};
