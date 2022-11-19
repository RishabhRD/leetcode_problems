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

using graph_t = std::vector<std::vector<int>>;

auto build_graph(int n, std::vector<std::vector<int>> const& edges) {
  std::vector graph(n, std::vector<int>());
  for (auto const& edge : edges) {
    auto const u = edge[0];
    auto const v = edge[1];
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  return graph;
}

auto make_dist_sum_helper(graph_t const& graph, int i,
                          std::vector<bool>& visited, int cur, int& res) {
  if (visited[i]) return;
  visited[i] = true;
  res += cur;
  for (auto n : graph[i]) {
    make_dist_sum_helper(graph, n, visited, cur + 1, res);
  }
}

auto make_dist_sum(graph_t const& graph) {
  auto const n = std::size(graph);
  std::vector visited(n, false);
  int res = 0;
  make_dist_sum_helper(graph, 0, visited, 0, res);
  return res;
}

int make_tree_size_helper(graph_t const& graph, int i,
                          std::vector<bool>& visited, std::vector<int>& dp) {
  if (visited[i]) return 0;
  visited[i] = true;
  int ans = 1;
  for (auto n : graph[i]) {
    ans += make_tree_size_helper(graph, n, visited, dp);
  }
  return dp[i] = ans;
}

auto make_tree_size(graph_t const& graph) {
  auto const n = std::size(graph);
  std::vector visited(n, false);
  std::vector res(n, 0);
  make_tree_size_helper(graph, 0, visited, res);
  return res;
}

auto make_tree_sum(int i, int parent, graph_t const& graph,
                   std::vector<int>& dp, std::vector<int> const& tree_size) {
  if (dp[i] != -1) return;
  dp[i] = dp[parent] + std::size(graph) - tree_size[i] - tree_size[i];
  for (auto n : graph[i]) {
    make_tree_sum(n, i, graph, dp, tree_size);
  }
}

class Solution {
 public:
  std::vector<int> sumOfDistancesInTree(int n,
                                        std::vector<std::vector<int>>& edges) {
    auto const graph = build_graph(n, edges);
    auto const tree_size = make_tree_size(graph);
    std::vector<int> ans(n, -1);
    ans[0] = make_dist_sum(graph);
    for (auto n : graph[0]) make_tree_sum(n, 0, graph, ans, tree_size);
    return ans;
  }
};
