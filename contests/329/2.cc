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
#include <ranges>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

class Solution {
 public:
  std::vector<std::vector<int>> sortTheStudents(
      std::vector<std::vector<int>>& scores, int k) {
    std::sort(std::begin(scores), std::end(scores),
              [k](auto const& a, auto const& b) { return a[k] > b[k]; });
    return scores;
  }
};
