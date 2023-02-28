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
  int minimumMoves(std::vector<std::vector<int>>& grid) {
    ll const n = grid.size();
    std::vector visited(n, std::vector(n, std::vector(2, false)));
    std::queue<std::tuple<ll, ll, ll>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = true;
    ll cur_level = 0;
    while (not std::empty(q)) {
      auto sz = q.size();
      while (sz--) {
        auto const [x, y, dir] = q.front();
        if (x == n - 1 && y == n - 2 && dir == 0) return cur_level;
        q.pop();
        if (dir == 0) {
          if (y + 2 < n && grid[x][y + 2] == 0 && !visited[x][y + 1][dir]) {
            q.push({x, y + 1, dir});
            visited[x][y + 1][dir] = true;
          }
          if (x + 1 < n && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0 &&
              !visited[x + 1][y][dir]) {
            q.push({x + 1, y, dir});
            visited[x + 1][y][dir] = true;
          }
          if (x + 1 < n && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0 &&
              !visited[x][y][1]) {
            q.push({x, y, 1});
            visited[x][y][1] = true;
          }
        } else {
          if (x + 2 < n && grid[x + 2][y] == 0 && !visited[x + 1][y][dir]) {
            q.push({x + 1, y, dir});
            visited[x + 1][y][dir] = true;
          }
          if (y + 1 < n && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0 &&
              !visited[x][y + 1][dir]) {
            q.push({x, y + 1, dir});
            visited[x][y + 1][dir] = true;
          }
          if (y + 1 < n && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0 &&
              !visited[x][y][0]) {
            q.push({x, y, 0});
            visited[x][y][0] = true;
          }
        }
      }
      ++cur_level;
    }
    return -1;
  }
};
