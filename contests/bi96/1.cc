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
  int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> st{nums1.begin(), nums1.end()};
    for (auto n : nums2) {
      if (st.count(n)) return n;
    }
    return -1;
  }
};
