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

class Solution {
 public:
  long long minOperations(std::vector<int>& nums1, std::vector<int>& nums2,
                          int k) {
    if (k == 0) {
      if (nums1 == nums2)
        return 0;
      else
        return -1;
    }
    ll const n = nums1.size();
    ll to_increment = 0;
    ll to_decrement = 0;
    for (ll i = 0; i < n; ++i) {
      auto const diff = nums1[i] - nums2[i];
      if (std::abs(diff) % k != 0) return -1;
      if (diff < 0)
        to_increment += std::abs(diff) / k;
      else
        to_decrement += std::abs(diff) / k;
    }
    if (to_decrement == to_increment)
      return to_increment;
    else
      return -1;
  }
};
