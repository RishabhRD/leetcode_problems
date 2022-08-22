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

using matrix_t = std::vector<std::vector<int>>;

class Solution {
 public:
  matrix_t updateMatrix(matrix_t& mat) {
    auto const m = std::size(mat);
    auto const n = std::size(mat[0]);

    matrix_t res(m, std::vector(n, 0));
    std::vector visited(m, std::vector(n, false));
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          visited[i][j] = true;
          q.emplace(i, j);
        }
      }
    }

    int cur_level = 0;
    std::array<int, 4> incr_xs{-1, 1, 0, 0};
    std::array<int, 4> incr_ys{0, 0, -1, 1};
    while (!empty(q)) {
      auto qs = std::size(q);
      while (qs--) {
        auto [cur_x, cur_y] = q.front();
        q.pop();
        res[cur_x][cur_y] = cur_level;
        for (int i = 0; i < 4; ++i) {
          auto const incr_x = incr_xs[i];
          auto const incr_y = incr_ys[i];

          auto const x = cur_x + incr_x;
          auto const y = cur_y + incr_y;

          if (x >= 0 and y >= 0 and x < m and y < n and
              visited[x][y] == false) {
            visited[x][y] = true;
            q.emplace(x, y);
          }
        }
      }
      ++cur_level;
    }

    return res;
  }
};
