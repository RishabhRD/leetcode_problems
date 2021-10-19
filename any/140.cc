#include <unordered_set>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

bool contains(const unordered_set<string_view> &st, string_view str) {
  return st.find(str) != end(st);
}

void word_break(string_view str,
  const unordered_set<string_view> &st,
  size_t cur_idx,
  vector<string_view> &cur_path,
  vector<string> &res) {
  if (cur_idx == size(str)) {
    res.push_back(accumulate(next(cbegin(cur_path)),
      cend(cur_path),
      std::string(cur_path.front()),
      [](const string &s1, string_view s2) {
        return s1 + " " + std::string(s2);
      }));
  }
  for (size_t i = cur_idx; i < size(str); i++) {
    if (contains(st, str.substr(cur_idx, i - cur_idx + 1))) {
      cur_path.push_back(str.substr(cur_idx, i - cur_idx + 1));
      word_break(str, st, i + 1, cur_path, res);
      cur_path.pop_back();
    }
  }
}

class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string_view> st{ cbegin(wordDict), cend(wordDict) };
    vector<string_view> cur_path;
    vector<string> res;
    word_break(s, st, 0, cur_path, res);
    return res;
  }
};
