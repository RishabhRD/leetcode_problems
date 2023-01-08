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
  int maximumCount(std::vector<int>& nums) {
    auto const neg = std::count_if(std::begin(nums), std::end(nums),
                                   [](auto a) { return a < 0; });
    auto const pos = std::count_if(std::begin(nums), std::end(nums),
                                   [](auto a) { return a > 0; });
    return std::max(neg, pos);
  }
};
