#include <queue>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;


class Solution {
public:
  int swimInWater(vector<vector<int>> &grid) {
    int n = size(grid);
    auto is_in = [=](int x, int y) {
      return x >= 0 and y >= 0 and x < n and y < n;
    };
    priority_queue<tuple<int, int, int>,
      vector<tuple<int, int, int>>,
      greater<tuple<int, int, int>>>
      pq;
    pq.emplace(grid[0][0], 0, 0);
    vector seen(n, vector<bool>(n));
    seen[0][0] = true;
    constexpr static pair<int, int> dir[] = {
      { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 }
    };
    int cur_res = 0;
    while (not empty(pq)) {
      auto [t, ux, uy] = pq.top();
      cur_res = max(cur_res, t);
      if (ux == n - 1 and uy == n - 1) return cur_res;
      pq.pop();
      for (const auto &[incr_x, incr_y] : dir) {
        int vx = ux + incr_x;
        int vy = uy + incr_y;
        if (is_in(vx, vy) and not seen[vx][vy]) {
          pq.emplace(grid[vx][vy], vx, vy);
          seen[vx][vy] = true;
        }
      }
    }
    return cur_res;
  }
};
