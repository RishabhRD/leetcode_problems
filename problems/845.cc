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

template <typename InIter, typename OutIter, typename Comparator>
auto scan_with_comparision(InIter begin, InIter end, OutIter out,
                           Comparator comp) {
  *out = 0;
  ++out;
  auto prev = begin;
  int prev_value = 0;
  for (auto cur = std::next(begin); cur != end; ++cur) {
    if (comp(*prev, *cur)) {
      *out = ++prev_value;
    } else {
      *out = (prev_value = 0);
    }
    ++out;
    prev = cur;
  }
}

auto scan_left_increasing(std::vector<int> const& arr) {
  std::vector<int> res(std::size(arr));
  scan_with_comparision(std::cbegin(arr), std::cend(arr), std::begin(res),
                        std::less{});
  return res;
}

auto scan_right_decreasing(std::vector<int> const& arr) {
  std::vector<int> res(std::size(arr));
  scan_with_comparision(std::crbegin(arr), std::crend(arr), std::rbegin(res),
                        std::less{});
  return res;
}

class Solution {
 public:
  int longestMountain(std::vector<int>& arr) {
    if (arr.size() < 3) return 0;
    auto const n = std::size(arr);
    auto left_increasing = scan_left_increasing(arr);
    auto right_decreasing = scan_right_decreasing(arr);
    /* for (auto n : left_increasing) std::cout << n << ' '; */
    /* std::cout << std::endl; */
    /* for (auto n : right_decreasing) std::cout << n << ' '; */
    /* std::cout << std::endl; */
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
      if (left_increasing[i] != 0 and right_decreasing[i] != 0) {
        ans = std::max(ans, 1 + left_increasing[i] + right_decreasing[i]);
      }
    }
    return ans;
  }
};
