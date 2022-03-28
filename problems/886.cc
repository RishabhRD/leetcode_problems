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
  vector<vector<int>> graph(n + 1);
  for(const auto& e : edges){
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  return graph;
}

bool dfs(const vector<vector<int>>& graph, const int cur_node, const int color, vector<int>& colors){
  if(colors[cur_node] != 0) return colors[cur_node] == color;
  colors[cur_node] = color;
  for(const auto node : graph[cur_node]){
    if(not dfs(graph, node, -color, colors)){
      return false;
    }
  }
  return true;
}

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
      const auto graph = get_graph(n, dislikes);
      vector<int> colors(n + 1);
      for(int i = 0; i < n; i++){
        if(colors[i] == 0 and (not dfs(graph, i, 1, colors))){
          return false;
        }
      }
      return true;
    }
};
