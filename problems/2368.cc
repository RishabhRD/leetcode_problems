#include <algorithm>
#include <array>
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

using edges_t = std::vector<std::vector<int>>;
using graph_t = std::vector<std::vector<int>>;

auto make_graph_from_edges(int n, edges_t edges) {
  graph_t graph(n);
  for (auto const& edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }
  return graph;
}

auto make_idx_restricted(int n, std::vector<int> const& restricted) {
  std::vector<bool> res(n);
  for (auto node : restricted) {
    res[node] = true;
  }
  return res;
}

auto dfs(graph_t const& graph, int n, std::vector<bool>& visited,
         std::vector<bool> const& restricted) {
  if (restricted[n] || visited[n]) return 0;
  visited[n] = true;
  int num_visited = 1;
  for (auto neighbor : graph[n]) {
    num_visited += dfs(graph, neighbor, visited, restricted);
  }
  return num_visited;
}

class Solution {
 public:
  int reachableNodes(int n, edges_t& edges, std::vector<int>& restricted) {
    auto const graph = make_graph_from_edges(n, edges);
    std::vector<bool> visited(n);
    return dfs(graph, 0, visited, make_idx_restricted(n, restricted));
  }
};
