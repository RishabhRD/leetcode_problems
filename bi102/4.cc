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

using namespace std;
constexpr auto inf = std::numeric_limits<long long>::max();

auto dijkstra(int n, vector<vector<pair<ll, ll>>> const& graph, int src) {
  vector<long long> dist(n, inf);
  dist[src] = 0;
  using pii = pair<long long, int>;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, src});
  while (not empty(pq)) {
    auto [cost, u] = pq.top();
    pq.pop();
    if (cost > dist[u]) continue;
    for (auto [v, w] : graph[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

class Graph {
  std::vector<std::vector<std::pair<ll, ll>>> graph;

 public:
  Graph(int n, std::vector<std::vector<int>>& edges) : graph(n) {
    for (auto const& edge : edges) {
      auto const x = edge[0];
      auto const y = edge[1];
      auto const w = edge[2];
      graph[x].push_back({y, w});
    }
  }

  void addEdge(std::vector<int> edge) {
    auto const x = edge[0];
    auto const y = edge[1];
    auto const w = edge[2];
    graph[x].push_back({y, w});
  }

  int shortestPath(int node1, int node2) {
    return dijkstra(graph.size(), graph, node1)[node2];
  }
};
