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

auto get_graph(const int n, const vector<vector<int>> &edges) {
  vector<vector<int>> graph(n);
  for (const auto &edge : edges) { graph[edge[0]].push_back(edge[1]); }
  return graph;
}

bool dfs(const vector<vector<int>> &graph,
  const int cur_node,
  vector<vector<int>>& dp,
  const int target) {
  if(dp[cur_node][target] != -1) return dp[cur_node][target];
  if (cur_node == target) {
    return dp[cur_node][target] = true;
  }
  for (const auto node : graph[cur_node]) {
    if (dfs(graph, node, dp, target)) {
      return dp[cur_node][target] = 1;
    }
  }
  return dp[cur_node][target] = 0;
}

class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses,
    vector<vector<int>> &prerequisites,
    vector<vector<int>> &queries) {
    const auto graph = get_graph(numCourses, prerequisites);
    vector<bool> ans;
    vector visited(numCourses, vector<int>(numCourses, -1));
    transform(cbegin(queries),
      cend(queries),
      back_inserter(ans),
      [&](const auto &query) {
        return dfs(graph, query[0], visited, query[1]);
      });
    return ans;
  }
};
