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
  std::vector<std::string> sortPeople(std::vector<std::string>& names,
                                      std::vector<int>& heights) {
    std::vector<std::pair<int, std::string>> vec;
    auto const n = std::size(names);
    for (int i = 0; i < n; ++i) {
      vec.push_back({heights[i], names[i]});
    }
    std::sort(std::begin(vec), std::end(vec), std::greater{});
    std::vector<std::string> res;
    for (auto [a, b] : vec) {
      res.push_back(b);
    }
    return res;
  }
};
