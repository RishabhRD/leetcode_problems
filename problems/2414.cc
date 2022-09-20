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
  int longestContinuousSubstring(std::string s) {
    auto prev = s[0];
    int max_len = 1;
    int cur_len = 1;
    for (int i = 1; i < std::size(s); ++i) {
      if (s[i] - s[i - 1] == 1) {
        ++cur_len;
      } else {
        cur_len = 1;
      }
      max_len = std::max(max_len, cur_len);
    }
    return max_len;
  }
};
