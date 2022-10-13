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
  bool canChange(std::string start, std::string target) {
    std::string no_blank_start;
    std::copy_if(std::begin(start), std::end(start),
                 std::back_inserter(no_blank_start),
                 [](auto ele) { return ele != '_'; });
    std::string no_blank_target;
    std::copy_if(std::begin(target), std::end(target),
                 std::back_inserter(no_blank_target),
                 [](auto ele) { return ele != '_'; });
    if (no_blank_start != no_blank_target) return false;

    std::vector<std::pair<int, char>> p;
    for (int i = 0; i < std::size(target); ++i) {
      if (target[i] == 'L')
        p.push_back({i, 'L'});
      else if (target[i] == 'R')
        p.push_back({i, 'R'});
    }

    int cur = 0;
    for (int i = 0; i < std::size(start); ++i) {
      if (start[i] == '_') continue;
      auto const target_idx = p[cur].first;
      if (start[i] == 'L') {
        if (target_idx > i) return false;
      } else {
        if (target_idx < i) return false;
      }
      ++cur;
    }
    return true;
  }
};
