#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

constexpr auto inf = numeric_limits<long long>::max();

auto get_graph(int n, vector<vector<int>> const &edges) {
  vector<vector<pair<int, int>>> graph(n);
  for (auto const &edge : edges) {
    graph[edge[0]].push_back(pair{ edge[1], edge[2] });
  }
  return graph;
}

auto get_reversed_graph(int n, vector<vector<int>> const &edges) {
  vector<vector<pair<int, int>>> graph(n);
  for (auto const &edge : edges) {
    graph[edge[1]].push_back(pair{ edge[0], edge[2] });
  }
  return graph;
}

auto dijkstra(int n, vector<vector<pair<int, int>>> const &graph, int src) {
  vector<long long> dist(n, inf);
  dist[src] = 0;
  using pii = pair<long long, int>;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({ 0, src });
  while (not empty(pq)) {
    auto [cost, u] = pq.top();
    pq.pop();
    if (cost > dist[u]) continue;
    for (auto [v, w] : graph[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({ dist[v], v });
      }
    }
  }
  return dist;
}

class Solution {
public:
  long long minimumWeight(int n,
    vector<vector<int>> &edges,
    int src1,
    int src2,
    int dest) {
    auto const graph = get_graph(n, edges);
    auto const reverse_graph = get_reversed_graph(n, edges);
    auto const dists1 = dijkstra(n, graph, src1);
    auto const dists2 = dijkstra(n, graph, src2);
    auto const dists3 = dijkstra(n, reverse_graph, dest);
    long long ans = inf;
    for (int i = 0; i < n; i++) {
      if (dists1[i] == inf or dists2[i] == inf or dists3[i] == inf) continue;
      ans = min(ans, dists1[i] + dists2[i] + dists3[i]);
    }
    return ans == inf ? -1 : ans;
  }
};

int main() {
  vector<vector<int>> edges{ { 0, 1, 1 }, { 2, 1, 1 } };
  Solution sol;
  cout << sol.minimumWeight(3, edges, 0, 1, 2) << endl;
}
