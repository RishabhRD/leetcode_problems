#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

auto make_string_view(std::string const& str, std::size_t idx, std::size_t n) {
  auto str_ptr = str.c_str();
  return std::string_view{str_ptr + idx, n};
}

class Solution {
 public:
  std::vector<std::string> findRepeatedDnaSequences(std::string const s) {
    auto const n = std::size(s);
    if (n < 10) return {};
    std::unordered_map<std::string_view, int> cnt_map{
        {make_string_view(s, 0, 10), 1},
    };
    for (int cur_idx = 10; cur_idx < n; ++cur_idx) {
      std::string_view const cur_dna_seq(make_string_view(s, cur_idx - 9, 10));
      ++cnt_map[cur_dna_seq];
    }
    std::vector<std::string> res;
    for (auto& [str, freq] : cnt_map) {
      if (freq > 1) res.push_back(std::string(str));
    }
    return res;
  }
};
