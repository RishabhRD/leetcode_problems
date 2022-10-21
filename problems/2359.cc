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

constexpr int inf = 1e6;

auto shortest_path(std::vector<std::vector<int>> const& graph, int src) {
  auto const n = std::size(graph);
  std::vector dist(n, inf);
  std::queue<int> q;
  std::vector visited(n, false);
  int cur_level = 0;
  q.push(src);
  visited[src] = true;
  while (not std::empty(q)) {
    auto sz = q.size();
    while (sz--) {
      auto const u = q.front();
      dist[u] = cur_level;
      q.pop();
      for (auto v : graph[u]) {
        if (not visited[v]) {
          q.push(v);
          visited[v] = true;
        }
      }
    }
    ++cur_level;
  }
  return dist;
}

class Solution {
 public:
  int closestMeetingNode(std::vector<int>& edges, int node1, int node2) {
    auto const n = std::size(edges);
    std::vector graph(n, std::vector<int>());
    for (int i = 0; i < n; ++i) {
      if (edges[i] != -1) graph[i].push_back(edges[i]);
    }
    auto const dist1 = shortest_path(graph, node1);
    auto const dist2 = shortest_path(graph, node2);
    auto min_dist = inf;
    auto ans_node = -1;
    for (int i = 0; i < n; ++i) {
      if (dist1[i] == inf || dist2[i] == inf) continue;
      auto const dist = std::max(dist1[i], dist2[i]);
      if (dist < min_dist) {
        min_dist = dist;
        ans_node = i;
      }
    }
    return ans_node;
  }
};
