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

void dfs(std::vector<std::vector<int>> const& graph, int i,
         std::vector<int>& color) {
  if (color[i] != -1) return;
  for (int cur_color = 1; cur_color <= 4; ++cur_color) {
    if (std::none_of(std::begin(graph[i]), std::end(graph[i]),
                     [&](auto ele) { return color[ele] == cur_color; })) {
      color[i] = cur_color;
      break;
    }
  }
  for (auto ele : graph[i]) dfs(graph, ele, color);
}

class Solution {
 public:
  std::vector<int> gardenNoAdj(int n, std::vector<std::vector<int>>& paths) {
    std::vector<std::vector<int>> graph(n + 1);
    for (auto const& path : paths) {
      graph[path[0]].push_back(path[1]);
      graph[path[1]].push_back(path[0]);
    }
    std::vector color(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
      dfs(graph, i, color);
    }
    color.erase(std::begin(color));
    return color;
  }
};
