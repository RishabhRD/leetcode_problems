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

auto diff(std::string_view a, std::string_view b) {
  auto const n = std::size(a);
  int diff = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) ++diff;
  }
  return diff;
}

bool is_eligible(std::string_view query,
                 std::vector<std::string> const& dictionary) {
  return std::any_of(
      std::begin(dictionary), std::end(dictionary),
      [&](std::string_view word) { return diff(query, word) <= 2; });
}

class Solution {
 public:
  std::vector<std::string> twoEditWords(std::vector<std::string>& queries,
                                        std::vector<std::string>& dictionary) {
    std::vector<std::string> res;
    std::copy_if(
        std::begin(queries), std::end(queries), std::back_inserter(res),
        [&](std::string_view query) { return is_eligible(query, dictionary); });
    return res;
  }
};
