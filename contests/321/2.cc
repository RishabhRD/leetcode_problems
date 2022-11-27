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

using ll = long long;

class Solution {
 public:
  int appendCharacters(std::string s, std::string t) {
    auto const m = std::size(s);
    auto const n = std::size(t);
    int i = 0;
    int j = 0;
    int match = 0;
    while (i < m and j < n) {
      if (s[i] == t[j]) {
        ++match;
        ++i;
        ++j;
      } else {
        ++i;
      }
    }
    return n - match;
  }
};
