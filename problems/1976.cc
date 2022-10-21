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

using graph_t = std::vector<std::vector<std::pair<ll, ll>>>;
constexpr ll inf = 4 * (1e12);
constexpr ll mod = 1e9 + 7;

auto build_graph(int n, std::vector<std::vector<int>> const& roads) {
  graph_t graph(n);
  for (auto const& road : roads) {
    auto const x = road[0];
    auto const y = road[1];
    auto const w = road[2];
    graph[x].push_back({y, w});
    graph[y].push_back({x, w});
  }
  return graph;
}

auto dijsktra(graph_t const& graph, int src) {
  auto const n = std::size(graph);
  std::vector dist(n, inf);
  std::vector<ll> ways(n, 0);
  dist[src] = 0;
  ways[src] = 1;
  using pii = std::pair<ll, ll>;
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
  pq.push({0, src});
  while (not std::empty(pq)) {
    auto const [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    for (auto [v, w] : graph[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        ways[v] = ways[u];
        pq.push({dist[v], v});
      } else if (dist[v] == dist[u] + w) {
        ways[v] = (ways[v] + ways[u]) % mod;
      }
    }
  }
  return ways;
}

class Solution {
 public:
  int countPaths(int n, std::vector<std::vector<int>>& roads) {
    auto const graph = build_graph(n, roads);
    return dijsktra(graph, 0)[n - 1];
  }
};
