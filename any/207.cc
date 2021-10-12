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

auto get_graph(const int n, const vector<vector<int>>& edges){
  vector<vector<int>> graph(n);
  for(const auto& e : edges){
    graph[e[0]].push_back(e[1]);
  }
  return graph;
}

bool dfs(const vector<vector<int>>& graph, const int cur_node, vector<bool>& visited, vector<bool>& cur_rec){
  if(cur_rec[cur_node]) return true;
  if(visited[cur_node]) return false;
  cur_rec[cur_node] = true;
  visited[cur_node] = true;
  for(auto node : graph[cur_node]){
    if(dfs(graph, node, visited, cur_rec)){
      return true;
    }
  }
  cur_rec[cur_node] = false;
  return false;
}

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
      const auto graph = get_graph(n, edges);
      vector<bool> visited(n);
      vector<bool> cur_rec(n);
      for(int i = 0; i < n; i++){
        if(dfs(graph, i, visited, cur_rec)){
          return false;
        }
      }
      return true;
    }
};
