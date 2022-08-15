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

class Solution {
 public:
  bool isSubsequence(std::string s, std::string t) {
    if (s.size() > t.size()) {
      return false;
    }
    auto const s_size = s.size();
    auto const t_size = t.size();
    std::size_t s_ptr = 0;
    std::size_t t_ptr = 0;
    while (s_ptr < s_size and t_ptr < t_size) {
      if (s[s_ptr] == t[t_ptr]) {
        ++s_ptr;
        ++t_ptr;
      } else {
        ++t_ptr;
      }
    }
    return s_ptr == s.size();
  }
};
