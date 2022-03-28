#include <unordered_set>
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

auto get_graph(const int n, const vector<vector<int>>& connections){
  vector<vector<int>> graph(n);
  for(const auto& edge : connections){
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(-edge[0]);
  }
  return graph;
}

int dfs(vector<vector<int>>& graph, int cur_node, vector<bool>& visited){
  int num_required = 0;
  visited[cur_node] = true;
  for(auto n : graph[cur_node]){
    if(not visited[abs(n)]){
      num_required += (n > 0);
      num_required += dfs(graph, abs(n), visited);
    }
  }
  return num_required;
}

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
      auto graph = get_graph(n, connections);
      vector<bool> visited(n);
      return dfs(graph, 0, visited);
    }
};
