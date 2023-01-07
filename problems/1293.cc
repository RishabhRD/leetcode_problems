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
  int shortestPath(std::vector<std::vector<int>> const& grid, int k) {
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    std::vector visited(k + 1, std::vector(m, std::vector(n, false)));
    std::queue<std::tuple<ll, ll, ll>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = true;
    ll cur_level = 0;
    while (not std::empty(q)) {
      auto sz = q.size();
      while (sz--) {
        auto const [cur_k, x, y] = q.front();
        q.pop();
        if (x == m - 1 && y == n - 1) {
          return cur_level;
        }
        constexpr static ll dx[] = {1, -1, 0, 0};
        constexpr static ll dy[] = {0, 0, -1, 1};
        for (ll i = 0; i < 4; ++i) {
          auto const nx = x + dx[i];
          auto const ny = y + dy[i];
          if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
          if (grid[nx][ny] == 0) {
            if (visited[cur_k][nx][ny] == false) {
              q.push({cur_k, nx, ny});
              visited[cur_k][nx][ny] = true;
            }
          } else {
            if (cur_k < k && visited[cur_k + 1][nx][ny] == false) {
              q.push({cur_k + 1, nx, ny});
              visited[cur_k + 1][nx][ny] = true;
            }
          }
        }
      }
      ++cur_level;
    }
    return -1;
  }
};
