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

using graph_t = std::vector<std::vector<std::pair<int, int>>>;

auto build_graph(std::vector<std::vector<int>> const& edges, int n) {
  std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
  for (auto const& edge : edges) {
    graph[edge[0]].push_back({edge[1], edge[2]});
    graph[edge[1]].push_back({edge[0], edge[2]});
  }
  return graph;
}

auto dijkstra(graph_t const& graph, int src) {
  auto const n = std::size(graph);
  std::vector<long> dist(n, INT32_MAX);
  dist[src] = 0;
  using pii = std::pair<long, int>;
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
  pq.push({0, src});
  while (not std::empty(pq)) {
    auto [cur_dist, cur_node] = pq.top();
    pq.pop();
    for (auto [neigh, w] : graph[cur_node]) {
      if (dist[neigh] > cur_dist + w) {
        dist[neigh] = cur_dist + w;
        pq.push({dist[neigh], neigh});
      }
    }
  }
  return dist;
}

int dfs(graph_t const& graph, int i, std::vector<long> const& dist,
        std::vector<int>& num_paths) {
  constexpr static int mod = 1e9 + 7;

  if (i == std::size(graph) - 1) {
    return 1;
  }

  if (num_paths[i] >= 0) return num_paths[i];

  int ans = 0;
  for (auto [neigh, w] : graph[i]) {
    if (dist[i] > dist[neigh]) {
      ans = (ans + dfs(graph, neigh, dist, num_paths)) % mod;
    }
  }
  return num_paths[i] = ans;
}

class Solution {
 public:
  int countRestrictedPaths(int n, std::vector<std::vector<int>>& edges) {
    auto const graph = build_graph(edges, n);
    auto const shortest_path = dijkstra(graph, n);
    std::vector<int> num_paths(n + 1, -1);
    auto const ans = dfs(graph, 1, shortest_path, num_paths);
    if (ans == -1) return 0;
    return ans;
  }
};
