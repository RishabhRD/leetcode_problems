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
  std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid) {
    std::vector<int> ans;
    for (ll j = 0; j < grid[0].size(); ++j) {
      ll max_len = 0;
      for (ll i = 0; i < grid.size(); ++i) {
        max_len = std::max<ll>(max_len, std::to_string(grid[i][j]).size());
      }
      ans.push_back(max_len);
    }
    return ans;
  }
};
