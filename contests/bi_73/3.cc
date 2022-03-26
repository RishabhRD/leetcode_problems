#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

auto get_graph(int n, vector<vector<int>> const &edges) {
  vector<vector<int>> graph(n);
  for (auto const &edge : edges) {
    graph[edge[0]].push_back(edge[1]);
  }
  return graph;
}

void dfs(int src, int ele, vector<vector<int>> const &graph,
         vector<vector<int>> &res, vector<bool> &visited) {
  visited[ele] = true;
  for (auto node : graph[ele]) {
    if (not visited[node]) {
      res[node].push_back(src);
      dfs(src, node, graph, res, visited);
    }
  }
}

class Solution {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    auto const graph = get_graph(n, edges);
    vector<vector<int>> res(n);
    for (int i = 0; i < n; i++) {
      vector<bool> visited(n);
      dfs(i, i, graph, res, visited);
    }
    return res;
  }
};
