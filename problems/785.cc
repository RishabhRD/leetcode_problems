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

bool dfs(const vector<vector<int>>& graph, int cur_node, int color, vector<int>& colors){
  if(colors[cur_node] != 0) return colors[cur_node] == color;
  colors[cur_node] = color;
  for(auto node : graph[cur_node]){
    if(not dfs(graph, node, -color, colors)){
      return false;
    }
  }
  return true;
}

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      vector<int> colors(size(graph));
      for(size_t i = 0; i < size(graph); i++){
        if(colors[i] == 0 and !dfs(graph, i, 1, colors)) return false;
      }
      return true;
    }
};
