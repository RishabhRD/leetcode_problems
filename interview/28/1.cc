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

bool has_cycle(vector<vector<int>>& graph, int cur_node, vector<bool>& visited, vector<bool>& cur_rec){
  if(cur_rec[cur_node]) return true;
  if(visited[cur_node]) return false;
  visited[cur_node] =  true;
  cur_rec[cur_node] = true;
  for(auto n : graph[cur_node]){
    if(has_cycle(graph, n, visited, cur_rec)) return true;
  }
  cur_rec[cur_node] = false;
  return false;
}

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    for(const auto& edge : prerequisites){
      graph[edge[0]].push_back(edge[1]);
    }
    vector<bool> visited(numCourses);
    vector<bool> cur_rec(numCourses);
    for(int i = 0; i < numCourses; i++){
      if(not visited[i]){
        if(has_cycle(graph, i, visited, cur_rec)) return false;
      }
    }
    return true;
  }
};
