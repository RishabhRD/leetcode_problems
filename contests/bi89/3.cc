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

bool is_ans(std::vector<int> const& vec, int n) {
  long long sum = 0;
  for (auto ele : vec) {
    sum += (n - ele);
    if (sum < 0) return false;
  }
  return true;
}

int binary_search(long long low, long long high, std::vector<int> const& vec) {
  if (low >= high) return high;
  auto const mid = (low + high) / 2;
  if (is_ans(vec, mid)) {
    return binary_search(low, mid, vec);
  } else {
    return binary_search(mid + 1, high, vec);
  }
}

class Solution {
 public:
  int minimizeArrayValue(std::vector<int>& nums) {
    auto const n = std::size(nums);
    long double zero = 0;
    long double const sum = std::reduce(std::begin(nums), std::end(nums), zero);
    auto const low = std::ceil(sum / n);
    auto const high = *std::max_element(std::begin(nums), std::end(nums));
    return binary_search(low, high, nums);
  }
};
