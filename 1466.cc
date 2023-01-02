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

auto make_graph(ll n, std::vector<std::vector<int>> const& connections) {
  std::vector<std::vector<int>> graph(n);
  for (auto const& edge : connections) {
    auto const x = edge[0];
    auto const y = edge[1];
    graph[x].push_back(y);
    graph[y].push_back(-x);
  }
  return graph;
}

ll dfs(std::vector<std::vector<int>> const& graph, ll cur, ll parent) {
  ll ans = 0;
  for (auto n : graph[cur]) {
    if (std::abs(n) != parent) {
      if (n > 0) ++ans;
      ans += dfs(graph, std::abs(n), cur);
    }
  }
  return ans;
}

class Solution {
 public:
  int minReorder(int n, std::vector<std::vector<int>>& connections) {
    auto const graph = make_graph(n, connections);
    return dfs(graph, 0, 0);
  }
};
