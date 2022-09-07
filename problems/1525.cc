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

auto make_left_distinct(std::string_view str) {
  std::array<bool, 128> arr{false};
  auto const n = std::size(str);
  std::vector ans(n, 0);
  for (int i = 0; i < n; ++i) {
    auto const c = str[i];
    arr[c] = true;
    ans[i] = std::count(std::cbegin(arr), std::cend(arr), true);
  }
  return ans;
}

auto make_right_distinct(std::string_view str) {
  std::array<bool, 128> arr{false};
  auto const n = std::size(str);
  std::vector ans(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    auto const c = str[i];
    arr[c] = true;
    ans[i] = std::count(std::cbegin(arr), std::cend(arr), true);
  }
  return ans;
}

class Solution {
 public:
  int numSplits(std::string s) {
    auto const left = make_left_distinct(s);
    auto const right = make_right_distinct(s);
    auto const n = std::size(s);
    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (left[i] == right[i + 1]) ++count;
    }
    return count;
  }
};
