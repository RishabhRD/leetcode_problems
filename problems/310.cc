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

using graph_t = std::vector<std::unordered_set<int>>;

auto build_graph(int n, std::vector<std::vector<int>> const& edges) {
  graph_t graph(n);
  for (auto const& edge : edges) {
    graph[edge[0]].insert(edge[1]);
    graph[edge[1]].insert(edge[0]);
  }
  return graph;
}

auto find_mht(graph_t graph) {
  std::vector<int> leaves;
  for (int node = 0; node < std::size(graph); ++node) {
    if (std::size(graph[node]) == 1) {
      leaves.push_back(node);
    }
  }
  auto cur_graph_size = std::size(graph);
  while (cur_graph_size > 2) {
    std::vector<int> new_leaves;
    for (auto leaf : leaves) {
      for (auto leaf_adj : graph[leaf]) {
        graph[leaf_adj].erase(leaf);
        if (std::size(graph[leaf_adj]) == 1) {
          new_leaves.push_back(leaf_adj);
        }
      }
    }
    cur_graph_size -= std::size(leaves);
    leaves = std::move(new_leaves);
  }
  return leaves;
}

auto handle_no_edges(int n, std::vector<int> mht) {
  if (std::size(mht) == 0) {
    mht.resize(n);
    std::iota(begin(mht), end(mht), 0);
  }
  return mht;
}

class Solution {
 public:
  std::vector<int> findMinHeightTrees(int n,
                                      std::vector<std::vector<int>>& edges) {
    return handle_no_edges(n, find_mht(build_graph(n, edges)));
  }
};
