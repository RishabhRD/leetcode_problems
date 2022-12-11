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

auto is_num(std::string_view str) {
  return std::all_of(std::begin(str), std::end(str), [](auto c) {
    auto const num = c - '0';
    return num >= 0 and num <= 9;
  });
}

class Solution {
 public:
  int maximumValue(std::vector<std::string>& strs) {
    auto score = [](std::string const& str) -> ll {
      if (is_num(str)) {
        return std::stoi(str);
      }
      return str.size();
    };

    std::vector<ll> nums;
    std::transform(std::begin(strs), std::end(strs), std::back_inserter(nums),
                   score);
    return *std::max_element(std::begin(nums), std::end(nums));
  }
};
