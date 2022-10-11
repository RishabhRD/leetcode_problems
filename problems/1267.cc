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

int calc_idx(int i, int j, int n) { return i * n + j; }

class dsu {
 public:
  std::vector<int> size;
  std::vector<int> parent;

  dsu(int N, int n) : size(N, 1), parent(N) {
    std::iota(std::begin(parent), std::end(parent), 0);
  }

  int find(int a) {
    if (parent[a] == a)
      return a;
    else
      return parent[a] = find(parent[a]);
  }

  void combine(int i, int j) {
    auto p_i = find(i);
    auto p_j = find(j);

    if (p_i == p_j) return;
    if (size[p_i] > size[p_j]) {
      parent[p_j] = p_i;
      size[p_i] += size[p_j];
    } else {
      parent[p_i] = p_j;
      size[p_j] += size[p_i];
    }
  }
};

class Solution {
 public:
  int countServers(std::vector<std::vector<int>> const& grid) {
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);

    dsu dsu(m * n, n);

    for (int i = 0; i < m; ++i) {
      int prev_pc = -1;
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          if (prev_pc == -1) {
            prev_pc = j;
          } else {
            dsu.combine(calc_idx(i, prev_pc, n), calc_idx(i, j, n));
          }
        }
      }
    }

    for (int j = 0; j < n; ++j) {
      int prev_pc = -1;
      for (int i = 0; i < m; ++i) {
        if (grid[i][j] == 1) {
          if (prev_pc == -1) {
            prev_pc = i;
          } else {
            dsu.combine(calc_idx(prev_pc, j, n), calc_idx(i, j, n));
          }
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < m * n; ++i) {
      if (dsu.parent[i] == i) {
        if (dsu.size[i] > 1) ans += dsu.size[i];
      }
    }
    return ans;
  }
};
