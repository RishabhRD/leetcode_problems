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

auto make_word_without(std::string_view const word, int ex) {
  std::string str;
  for (int i = 0; i < std::size(word); ++i) {
    if (i != ex) str += word[i];
  }
  return str;
}

template <typename Callback>
auto for_each_prev(std::string_view const word, Callback callback) {
  auto const n = std::size(word);
  for (int i = 0; i < n; ++i) {
    callback(make_word_without(word, i));
  }
}

class Solution {
 public:
  int longestStrChain(std::vector<std::string>& words) {
    auto const n = std::size(words);
    std::vector<int> dp(n, 0);
    std::sort(std::begin(words), std::end(words),
              [](std::string_view a, std::string_view b) {
                return a.size() < b.size();
              });

    std::unordered_map<std::string, int> idx_map;
    for (int i = 0; i < n; ++i) {
      auto const& word = words[i];
      for_each_prev(word, [&](auto prev_word) {
        if (idx_map.find(prev_word) != idx_map.end()) {
          dp[i] = std::max(dp[i], dp[idx_map[prev_word]] + 1);
        } else {
          dp[i] = std::max(dp[i], 1);
        }
      });
      idx_map[word] = i;
    }
    return *std::max_element(std::cbegin(dp), std::cend(dp));
  }
};
