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

auto make_visited(std::vector<std::vector<int>> const& nums) {
  std::vector<std::vector<bool>> res;
  for (auto const& num : nums) {
    std::vector visit(std::size(num), false);
    res.push_back(visit);
  }
  return res;
}

class Solution {
 public:
  std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums) {
    auto visited = make_visited(nums);
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    std::vector<int> res;
    while (not std::empty(q)) {
      auto [x, y] = q.front();
      q.pop();
      res.push_back(nums[x][y]);
      auto new_x = x + 1;
      auto new_y = y;
      if (new_x < nums.size() and new_y < nums[new_x].size() and
          not visited[new_x][new_y]) {
        q.push({new_x, new_y});
        visited[new_x][new_y] = true;
      }
      new_x = x;
      new_y = y + 1;
      if (new_x < nums.size() and new_y < nums[new_x].size() and
          not visited[new_x][new_y]) {
        q.push({new_x, new_y});
        visited[new_x][new_y] = true;
      }
    }
    return res;
  }
};
