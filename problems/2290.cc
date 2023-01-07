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
  int minimumObstacles(std::vector<std::vector<int>>& grid) {
    auto const m = grid.size();
    auto const n = grid[0].size();
    std::vector dist(m, std::vector<ll>(n, INT32_MAX));
    dist[0][0] = 0;
    using tii = std::tuple<ll, ll, ll>;
    std::deque<tii> pq;
    pq.push_back({0, 0, 0});
    while (not pq.empty()) {
      auto const [d, ux, uy] = pq.back();
      pq.pop_back();
      if (d > dist[ux][uy]) continue;
      constexpr static ll dx[] = {-1, 1, 0, 0};
      constexpr static ll dy[] = {0, 0, -1, 1};
      for (ll i = 0; i < 4; ++i) {
        auto const vx = ux + dx[i];
        auto const vy = uy + dy[i];
        if (vx < 0 || vy < 0 || vx >= m || vy >= n) continue;
        auto const w = grid[vx][vy] == 1 ? 1 : 0;
        if (dist[ux][uy] + w < dist[vx][vy]) {
          dist[vx][vy] = dist[ux][uy] + w;
          if (grid[vx][vy] == 0) {
            pq.push_back({dist[vx][vy], vx, vy});
          } else {
            pq.push_front({dist[vx][vy], vx, vy});
          }
        }
      }
    }
    return dist[m - 1][n - 1];
  }
};
