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

class dsu {
 public:
  std::vector<int> parent;
  std::vector<int> size;

  dsu(int n) : parent(n), size(n, 1) {
    std::iota(std::begin(parent), std::end(parent), 0);
  }

  int find(int n) {
    if (parent[n] == n) {
      return n;
    } else {
      return parent[n] = find(parent[n]);
    }
  }

  void combine(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;

    if (size[px] > size[py]) {
      size[px] += size[py];
      parent[py] = px;
    } else {
      size[py] += size[px];
      parent[px] = py;
    }
  }
};

int idx(int i, int j, int n) { return i * n + j; }

class Solution {
 public:
  int largestIsland(std::vector<std::vector<int>>& grid) {
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    dsu dsu(m * n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          constexpr static int dx[] = {0, 0, -1, 1};
          constexpr static int dy[] = {-1, 1, 0, 0};
          for (int k = 0; k < 4; ++k) {
            auto const new_x = i + dx[k];
            auto const new_y = j + dy[k];
            if (new_x >= 0 and new_y >= 0 and new_x < m and new_y < n and
                grid[new_x][new_y] == 1) {
              dsu.combine(idx(i, j, n), idx(new_x, new_y, n));
            }
          }
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < m * n; ++i) {
      ans = std::max(ans, dsu.size[dsu.find(i)]);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          std::unordered_map<int, int> mp;
          constexpr static int dx[] = {0, 0, -1, 1};
          constexpr static int dy[] = {-1, 1, 0, 0};
          for (int k = 0; k < 4; ++k) {
            auto const new_x = i + dx[k];
            auto const new_y = j + dy[k];
            if (new_x >= 0 and new_y >= 0 and new_x < m and new_y < n and
                grid[new_x][new_y] == 1) {
              mp[dsu.find(idx(new_x, new_y, n))] =
                  dsu.size[dsu.find(idx(new_x, new_y, n))];
            }
          }
          int sum = 0;
          for (auto [k, v] : mp) sum += v;
          ans = std::max(ans, sum + 1);
        }
      }
    }
    return ans;
  }
};
