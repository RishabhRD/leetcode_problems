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

auto idx(int i, int j, int n) { return i * n + j; }

auto make_graph(std::vector<std::vector<int>> const& grid) {
  auto const m = std::size(grid);
  auto const n = std::size(grid[0]);
  std::vector graph(m * n, std::vector<std::pair<int, int>>());
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i - 1 >= 0) {
        if (grid[i - 1][j] == 3) {
          graph[idx(i, j, n)].push_back({idx(i - 1, j, n), 0});
        } else {
          graph[idx(i, j, n)].push_back({idx(i - 1, j, n), 1});
        }
      }
      if (j - 1 >= 0) {
        if (grid[i][j - 1] == 1) {
          graph[idx(i, j, n)].push_back({idx(i, j - 1, n), 0});
        } else {
          graph[idx(i, j, n)].push_back({idx(i, j - 1, n), 1});
        }
      }
      if (i + 1 < m) {
        if (grid[i + 1][j] == 4) {
          graph[idx(i, j, n)].push_back({idx(i + 1, j, n), 0});
        } else {
          graph[idx(i, j, n)].push_back({idx(i + 1, j, n), 1});
        }
      }
      if (j + 1 < n) {
        if (grid[i][j + 1] == 2) {
          graph[idx(i, j, n)].push_back({idx(i, j + 1, n), 0});
        } else {
          graph[idx(i, j, n)].push_back({idx(i, j + 1, n), 1});
        }
      }
    }
  }
  return graph;
}

constexpr ll inf = INT32_MAX;

auto dijkstra(std::vector<std::vector<std::pair<int, int>>> const& graph,
              int src) {
  auto const n = std::size(graph);
  using pii = std::pair<ll, ll>;
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
  std::vector dist(n, inf);
  dist[src] = 0;
  pq.push({0, src});

  while (not std::empty(pq)) {
    auto const [d, u] = pq.top();
    pq.pop();
    for (auto const [v, w] : graph[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

class Solution {
 public:
  int minCost(std::vector<std::vector<int>>& grid) {
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    auto const graph = make_graph(grid);
    return dijkstra(graph, m * n - 1)[0];
  }
};
