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
  int minimumEffortPath(std::vector<std::vector<int>> const& heights) {
    auto const m = std::size(heights);
    auto const n = std::size(heights[0]);
    std::array<int, 4> dir_x = {0, 0, 1, -1};
    std::array<int, 4> dir_y = {1, -1, 0, 0};

    using tii = std::tuple<int, int, int>;
    std::priority_queue<tii, std::vector<tii>, std::greater<tii>> pq;
    pq.push({0, 0, 0});
    std::vector dist(m, std::vector(n, long(INT32_MAX)));
    dist[0][0] = 0;
    while (not std::empty(pq)) {
      auto [cur_d, x, y] = pq.top();
      pq.pop();
      if (cur_d > dist[x][y]) continue;
      if (x == m - 1 and y == n - 1) return cur_d;
      for (int i = 0; i < 4; ++i) {
        auto const new_x = x + dir_x[i];
        auto const new_y = y + dir_y[i];
        if (new_x >= 0 and new_x < m and new_y >= 0 and new_y < n) {
          auto const new_d =
              std::max(cur_d, std::abs(heights[new_x][new_y] - heights[x][y]));
          if (dist[new_x][new_y] > new_d) {
            dist[new_x][new_y] = new_d;
            pq.push({new_d, new_x, new_y});
          }
        }
      }
    }
    return -1;
  }
};
