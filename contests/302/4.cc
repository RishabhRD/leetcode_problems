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

auto common_factors(std::vector<int> const& nums) {
  std::unordered_set<int> st;
  int g = nums[0];
  for (auto ele : nums) g = std::gcd(g, ele);
  for (int i = 1; i * i <= g; ++i) {
    if (g % i == 0) {
      st.insert(i);
      st.insert(g / i);
    }
  }
  return st;
}

class Solution {
 public:
  int minOperations(std::vector<int>& nums, std::vector<int>& numsDivide) {
    auto const divisors = common_factors(numsDivide);
    std::sort(std::begin(nums), std::end(nums));
    int n = 0;
    for (auto ele : nums) {
      if (divisors.find(ele) == divisors.end()) {
        ++n;
      } else {
        break;
      }
    }
    if (n == std::size(nums)) return -1;
    return n;
  }
};
