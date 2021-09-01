#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
  auto min_len = std::accumulate(cbegin(strs),
    cend(strs),
    UINT32_MAX,
    [](const size_t prev_len, const auto &str) {
      return min(prev_len, size(str));
    });
  string new_str = "";
  for (int i = 0; i < min_len; i++) {
    const char cur_char = strs[0][i];
    if (all_of(cbegin(strs), cend(strs), [&](const auto &str) {
          return str[i] == cur_char;
        })) {
      new_str += cur_char;
    }else{
      break;
    }
  }
  return new_str;
}
