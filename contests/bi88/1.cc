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

auto remove_word(std::string word, int i) {
  word.erase(std::begin(word) + i);
  return word;
}

bool is_fine(std::string_view word) {
  std::unordered_map<char, int> mp;
  for (auto c : word) ++mp[c];
  std::unordered_map<int, int> freq;
  for (auto [k, v] : mp) ++freq[v];
  return freq.size() == 1;
}

class Solution {
 public:
  bool equalFrequency(std::string word) {
    auto const n = std::size(word);
    for (int i = 0; i < n; ++i) {
      if (is_fine(remove_word(word, i))) return true;
    }
    return false;
  }
};
