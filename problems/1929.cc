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
  std::vector<int> getConcatenation(std::vector<int>& nums) {
    auto const n = std::size(nums);
    nums.resize(n * 2);
    std::copy(std::begin(nums), std::begin(nums) + n, std::begin(nums) + n);
    return nums;
  }
};
