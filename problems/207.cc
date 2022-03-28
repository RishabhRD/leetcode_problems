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

auto get_graph(vector<vector<int>> const &pre) {
  unordered_map<int, vector<int>> graph;
  for (auto const &vec : pre) { graph[vec[0]].push_back(vec[1]); }
  return graph;
}

bool has_cycle(unordered_map<int, vector<int>> &graph,
  int i,
  vector<bool> &visited,
  vector<bool> &currently_visiting) {
  if (currently_visiting[i]) return true;
  if (visited[i]) return false;
  visited[i] = true;
  currently_visiting[i] = true;
  for (auto neigh : graph[i]) {
    if (has_cycle(graph, neigh, visited, currently_visiting)) return true;
  }
  currently_visiting[i] = false;
  return false;
}

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector visited(numCourses, false);
    vector is_cyclic(numCourses, false);
    auto graph = get_graph(prerequisites);
    for (int i = 0; i < numCourses; i++) {
      if (not visited[i]) {
        if (has_cycle(graph, i, visited, is_cyclic)) return false;
      }
    }
    return true;
  }
};
