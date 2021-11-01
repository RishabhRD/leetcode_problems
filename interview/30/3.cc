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

bool dfs(vector<vector<int>> &graph,
  int cur_node,
  int cur_color,
  vector<int> &color) {
  if (color[cur_node] == 0) {
    color[cur_node] = cur_color;
  } else {
    return color[cur_node] == cur_color;
  }
  for (auto n : graph[cur_node]) {
    if (not dfs(graph, n, -cur_color, color)) return false;
  }
  return true;
}

class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    const int n = size(graph);
    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
      if (colors[i] == 0) {
        if (not dfs(graph, i, 1, colors)) return false;
      }
    }
    return true;
  }
};
