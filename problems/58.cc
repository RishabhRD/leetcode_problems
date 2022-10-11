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
  int lengthOfLastWord(std::string s) {
    auto begin = std::find_if(std::rbegin(s), std::rend(s),
                              [](auto ele) { return ele != ' '; });
    return std::distance(begin, std::find(begin, std::rend(s), ' '));
  }
};
