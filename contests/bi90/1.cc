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

auto word_difference(std::string_view word) {
  std::vector<int> res;
  for (int i = 1; i < std::size(word); ++i) {
    res.push_back(word[i] - word[i - 1]);
  }
  return res;
}

class Solution {
 public:
  std::string oddString(std::vector<std::string>& words) {
    std::vector<std::vector<int>> difference(std::size(words));
    std::transform(std::begin(words), std::end(words), std::begin(difference),
                   word_difference);
    auto const& candidate = difference[0];
    if (std::count(std::begin(difference), std::end(difference), candidate) ==
        1) {
      return words[0];
    }
    auto itr = std::find_if(std::begin(difference), std::end(difference),
                            [&](auto const& ele) { return ele != candidate; });
    return words[itr - std::begin(difference)];
  }
};
