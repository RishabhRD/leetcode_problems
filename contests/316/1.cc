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

int to_int(char a, char b) {
  int na = a - '0';
  int nb = b - '0';
  return na * 10 + nb;
}

int to_int(std::string_view s) {
  auto hr = to_int(s[0], s[1]);
  auto min = to_int(s[3], s[4]);
  return hr * 60 + min;
}

class Solution {
 public:
  bool haveConflict(std::vector<std::string>& event1,
                    std::vector<std::string>& event2) {
    auto e1_start = to_int(event1[0]);
    auto e1_end = to_int(event1[1]);
    auto e2_start = to_int(event2[0]);
    auto e2_end = to_int(event2[1]);
    if (e1_start > e2_start) return haveConflict(event2, event1);
    return e1_end >= e2_start;
  }
};
