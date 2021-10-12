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

bool dfs(const vector<vector<int>>& graph, const int cur_node, vector<bool>& visited, vector<bool>& cur_rec, vector<int>& res){
  if(cur_rec[cur_node]) return true;
  if(visited[cur_node]) return false;
  visited[cur_node] = true;
  cur_rec[cur_node] = true;
  for(auto node : graph[cur_node]){
    if(dfs(graph, node, visited, cur_rec, res)){
      return true;
    }
  }
  res.push_back(cur_node);
  cur_rec[cur_node] = false;
  return false;
}

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
      const auto graph = get_graph(n, edges);
      vector<bool> visited(n);
      vector<bool> cur_rec(n);
      vector<int> res;
      for(int i = 0; i < n; i++){
        if(dfs(graph, i, visited, cur_rec, res)){
          return {};
        }
      }
      return res;
    }
};
