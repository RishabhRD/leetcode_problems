#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

auto all_substrings(std::string_view s, int i,
                    std::unordered_map<std::string_view, int>& strings,
                    std::vector<int>& res, int num_words, int word_size) {
  std::unordered_map<std::string_view, int> visited;
  int const n = std::size(s);
  int left = i;
  int count = 0;
  auto is_full = [&] { return count == num_words; };
  auto advance_window = [&] {
    auto substr = s.substr(left, word_size);
    left += word_size;
    --visited[substr];
    --count;
  };
  for (; i + word_size <= n; i += word_size) {
    auto const cur_word = s.substr(i, word_size);
    if (strings.find(cur_word) == strings.end()) {
      left = i + word_size;
      visited.clear();
      count = 0;
    } else {
      ++visited[cur_word];
      ++count;
      while (visited[cur_word] > strings[cur_word]) {
        advance_window();
      }
      if (is_full()) {
        res.push_back(left);
        advance_window();
      }
    }
  }
}

class Solution {
 public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string>& words) {
    int const num_words = words.size();
    int const word_size = words[0].size();
    if (word_size > std::size(s)) return {};
    int const sentence_size = num_words * word_size;

    std::vector<int> res;
    std::unordered_map<std::string_view, int> mp;
    for (std::string_view word : words) {
      ++mp[word];
    }
    for (int i = 0; i < word_size; ++i) {
      all_substrings(s, i, mp, res, num_words, word_size);
    }
    return res;
  }
};
