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

auto make_proceeding(std::string_view str) {
  auto const n = std::size(str);
  std::vector<int> zero_count(n);
  std::inclusive_scan(
      std::crbegin(str), std::crend(str), std::rbegin(zero_count),
      [](auto acc, auto ele) {
        if (ele == '0') {
          ++acc;
        }
        return acc;
      },
      0);
  return zero_count;
}

int dfs(std::vector<int> const& zeros, std::string_view str, int i) {
  if (i == std::size(str)) return 0;
  if (str[i] == '0') {
    return std::min(zeros[i], dfs(zeros, str, i + 1));
  } else {
    return std::min(1 + dfs(zeros, str, i + 1), zeros[i]);
  }
}

class Solution {
 public:
  int minFlipsMonoIncr(std::string s) {
    auto const proceeding_zeros = make_proceeding(s);
    return dfs(proceeding_zeros, s, 0);
  }
};
