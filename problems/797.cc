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

void dfs(const vector<vector<int>> &graph, vector<vector<int>>& res, vector<int>& path, int cur) {
  path.push_back(cur);
  if (cur == size(graph) - 1) {
    res.push_back(path);
  }else for (auto n : graph[cur]) { dfs(graph, res, path, n); }
  path.pop_back();
}

auto get_graph(const vector<vector<int>> &graph) {
  vector<vector<int>> all_paths;
  vector<int> cur_path;
  dfs(graph, all_paths, cur_path, 0);
  return all_paths;
}

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    return get_graph(graph);
  }
};
