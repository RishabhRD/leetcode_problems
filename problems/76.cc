#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

bool satisfies(array<int, 128> const& source, array<int, 128> const& target) {
  for (char c = 'a'; c <= 'z'; ++c) {
    if (source[c] < target[c]) return false;
  }
  for (char c = 'A'; c <= 'Z'; ++c) {
    if (source[c] < target[c]) return false;
  }
  return true;
}

auto get_char_count(string_view s) {
  array<int, 128> cnt{0};
  for (auto c : s) {
    ++cnt[c];
  }
  return cnt;
}

class Solution {
 public:
  string minWindow(string s_str, string t_str) {
    string_view s = s_str;
    string_view t = t_str;
    int const n = size(s);
    auto const t_cnt = get_char_count(t);
    array<int, 128> s_cnt{0};
    int i = 0;
    int j = 0;
    string_view res{s_str};
    bool found = false;
    while (j < n) {
      ++s_cnt[s[j]];
      while (satisfies(s_cnt, t_cnt)) {
        found = true;
        if (j - i + 1 < size(res)) {
          res = s.substr(i, j - i + 1);
        }
        --s_cnt[s[i]];
        ++i;
      }
      ++j;
    }
    return found ? string{res} : "";
  }
};
