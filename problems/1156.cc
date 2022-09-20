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

int max_stream_with_break(char c, int num_possible_breaks,
                          std::string_view str) {
  int low = 0;
  int num_breaks = 0;
  int max_len = 0;
  for (int high = 0; high < std::size(str); ++high) {
    if (str[high] != c) ++num_breaks;
    while (num_breaks > num_possible_breaks) {
      if (str[low] != c) --num_breaks;
      ++low;
    }
    max_len = std::max(max_len, high - low + 1);
  }
  return max_len;
}

class Solution {
 public:
  int maxRepOpt1(std::string text) {
    auto ans = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      int const num_ele_in_breaking_stream = max_stream_with_break(c, 1, text);
      int const num_c = std::count(std::begin(text), std::end(text), c);
      ans = std::max(ans, std::min(num_ele_in_breaking_stream, num_c));
    }
    return ans;
  }
};
