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
  std::vector<std::vector<int>> mergeArrays(
      std::vector<std::vector<int>>& nums1,
      std::vector<std::vector<int>>& nums2) {
    std::unordered_map<ll, ll> mp1;
    for (auto const& vec : nums1) {
      mp1[vec[0]] = vec[1];
    }
    std::unordered_map<ll, ll> mp2;
    for (auto const& vec : nums2) {
      mp2[vec[0]] = vec[1];
    }
    std::vector<std::vector<int>> ans;
    for (ll i = 1; i <= 1000; ++i) {
      auto const val = mp1[i] + mp2[i];
      if (val != 0) {
        ans.push_back(std::vector<int>({int(i), int(val)}));
      }
    }
    return ans;
  }
};
