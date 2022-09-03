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

template <typename InIter, typename OutIter>
auto kadane_scan(InIter begin, InIter end, OutIter out) {
  std::inclusive_scan(begin, end, out, [](auto folded, auto ele) {
    return std::max(folded + ele, ele);
  });
}

auto make_left_kadane_scan(std::vector<int> const& arr) {
  auto const n = std::size(arr);
  std::vector<int> scan(n, 0);
  kadane_scan(std::cbegin(arr), std::cend(arr), std::begin(scan));
  return scan;
}

auto make_right_kadane_scan(std::vector<int> const& arr) {
  auto const n = std::size(arr);
  std::vector<int> scan(n, 0);
  kadane_scan(std::crbegin(arr), std::crend(arr), std::rbegin(scan));
  return scan;
}

class Solution {
 public:
  int maximumSum(std::vector<int> const& arr) {
    auto const max_ending_here = make_left_kadane_scan(arr);
    auto const max_starting_here = make_right_kadane_scan(arr);

    auto const max_subarray_sum = *std::max_element(
        std::cbegin(max_ending_here), std::cend(max_ending_here));

    auto max_with_deleting = INT32_MIN;
    for (int i = 1; i < std::size(max_ending_here) - 1; ++i) {
      max_with_deleting = std::max(
          max_with_deleting, max_ending_here[i - 1] + max_starting_here[i + 1]);
    }
    return std::max(max_subarray_sum, max_with_deleting);
  }
};
