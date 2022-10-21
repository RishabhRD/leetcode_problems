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

double centre_dist(double x1, double y1, double x2, double y2) {
  return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool is_connected(std::vector<int> const& b1, std::vector<int> const& b2) {
  auto const x1 = b1[0];
  auto const x2 = b2[0];
  auto const y1 = b1[1];
  auto const y2 = b2[1];
  auto const r1 = b1[2];
  auto const r2 = b2[2];
  auto const c1c2 = centre_dist(x1, y1, x2, y2);
  return r1 >= c1c2;
}

int dfs(std::vector<std::vector<int>> const& graph, int i,
        std::vector<bool>& visited) {
  if (visited[i]) return 0;
  visited[i] = 1;
  int ans = 1;
  for (auto n : graph[i]) {
    ans += dfs(graph, n, visited);
  }
  return ans;
}

class Solution {
 public:
  int maximumDetonation(std::vector<std::vector<int>>& bombs) {
    auto const n = std::size(bombs);
    std::vector graph(n, std::vector<int>());
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (is_connected(bombs[i], bombs[j])) {
          graph[i].push_back(j);
        }
      }
    }
    int max = 1;
    for (int i = 0; i < n; ++i) {
      std::vector dp(n, false);
      max = std::max(max, dfs(graph, i, dp));
    }
    return max;
  }
};
