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

auto create_graph(int n, vector<vector<int>> &edges) {
  vector graph(n, vector<int>());
  for (auto const &edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }
  return graph;
}

void dfs(int i, vector<vector<int>> const &graph, vector<bool> &visited) {
  visited[i] = true;
  for (int n : graph[i]) {
    if (not visited[n]) { dfs(n, graph, visited); }
  }
}

int num_connected_components(int n, vector<vector<int>> const &graph) {
  vector visited(n, false);
  int num_components = 0;
  for (int i = 0; i < n; i++) {
    if (not visited[i]) {
      num_components++;
      dfs(i, graph, visited);
    }
  }
  return num_components;
}

class dsu {
  vector<int> parent;

public:
  dsu(int n) : parent(n, -1) {}

  int find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = find(parent[x]);
  }

  void combine(int x, int y) {
    int par_x = find(x);
    int par_y = find(y);
    if (par_x != par_y) parent[par_y] = par_x;
  }

  int num_components() const {
    return count_if(begin(parent), end(parent), [](int i) { return i == -1; });
  }
};

auto create_dsu_from_edges(int n, vector<vector<int>> const &connections) {
  dsu graph(n);
  for (auto const &edge : connections) { graph.combine(edge[0], edge[1]); }
  return graph;
}

class Solution {
public:
  int makeConnected_dfs(int n, vector<vector<int>> &connections) {
    if (size(connections) < n - 1) return -1;
    auto const graph = create_graph(n, connections);
    return num_connected_components(n, graph) - 1;
  }

  int makeConnected(int n, vector<vector<int>> &connections) {
    if (size(connections) < n - 1) return -1;
    auto const graph = create_dsu_from_edges(n, connections);
    return graph.num_components() - 1;
  }
};
