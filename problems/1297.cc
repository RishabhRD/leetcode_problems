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
  int maxFreq(std::string str, int maxLetters, int minSize, int maxSize) {
    std::string_view s = str;
    std::unordered_map<std::string_view, int> freq;
    auto const k = std::size(s) - minSize + 1;
    for (int i = 0; i < k; ++i) {
      std::array<bool, 26> uniq{false};
      auto cur_str = s.substr(i, minSize);
      for (auto c : cur_str) uniq[c - 'a'] = true;
      if (std::count(std::begin(uniq), std::end(uniq), true) <= maxLetters) {
        ++freq[cur_str];
      }
    }
    int ans = 0;
    for (auto [a, b] : freq) {
      ans = std::max(ans, b);
    }
    return ans;
  }
};
