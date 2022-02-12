#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

auto get_graph(vector<vector<int>> &pre) {
  unordered_map<int, vector<int>> graph;
  for (auto const &edges : pre) { graph[edges[1]].push_back(edges[0]); }
  return graph;
}

bool has_cycle(unordered_map<int, vector<int>> &graph,
  int i,
  vector<bool> &visited,
  vector<bool> &currently_visited,
  vector<int> &res) {
  if (currently_visited[i]) { return true; }
  if (visited[i]) return false;
  visited[i] = true;
  currently_visited[i] = true;
  for (auto n : graph[i]) {
    if (has_cycle(graph, n, visited, currently_visited, res)) return true;
  }
  res.push_back(i);
  currently_visited[i] = false;
  return false;
}

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector visited(numCourses, false);
    vector currently_visited(numCourses, false);
    auto graph{ get_graph(prerequisites) };
    vector<int> res;
    for (int i = 0; i < numCourses; i++) {
      if (has_cycle(graph, i, visited, currently_visited, res)) {
        res.clear();
        break;
      }
    }
    reverse(begin(res), end(res));
    return res;
  }
};
