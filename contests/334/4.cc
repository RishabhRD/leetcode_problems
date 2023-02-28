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

// [[0,1 ,99]
//  [3,99,99]
//  [4,5 ,6]]
using ll = long long;

class Solution {
 public:
  int minimumTime(std::vector<std::vector<int>>& grid) {
    constexpr static ll dx[] = {0, 0, -1, 1};
    constexpr static ll dy[] = {-1, 1, 0, 0};
    ll const m = grid.size();
    ll const n = grid[0].size();
    std::vector dist(m, std::vector<ll>(n, INT32_MAX));
    dist[0][0] = 0;
    using tii = std::tuple<ll, ll, ll>;
    std::priority_queue<tii, std::vector<tii>, std::greater<tii>> pq;
    ll count = 0;
    for (ll i = 0; i < 4; ++i) {
      auto const vx = dx[i];
      auto const vy = dy[i];
      if (vx < 0 || vy < 0 || vx >= m || vy >= n) continue;
      if (grid[vx][vy] > 1) continue;
      ++count;
    }
    if (count == 0) return -1;
    pq.push({0, 0, 0});
    while (not std::empty(pq)) {
      auto [cur_time, ux, uy] = pq.top();
      pq.pop();
      if (cur_time > dist[ux][uy]) continue;
      for (ll i = 0; i < 4; ++i) {
        auto const vx = ux + dx[i];
        auto const vy = uy + dy[i];
        if (vx < 0 || vy < 0 || vx >= m || vy >= n) continue;
        auto w = grid[vx][vy] - cur_time;
        if (w <= 0)
          w = 1;
        else if (w % 2 == 0)
          ++w;
        if (dist[vx][vy] > w + cur_time) {
          dist[vx][vy] = w + cur_time;
          pq.push({dist[vx][vy], vx, vy});
        }
      }
    }
    return dist[m - 1][n - 1];
  }
};
