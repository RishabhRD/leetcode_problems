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

auto get_graph(int n, vector<vector<int>>& roads){
  vector<unordered_set<int>> graph(n);
  for(const auto& road : roads){
    graph[road[0]].insert(road[1]);
    graph[road[1]].insert(road[0]);
  }
  return graph;
}

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
      const auto graph = get_graph(n, roads);
      int count = 0;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(i == j) continue;
          int degree = size(graph[i]) + size(graph[j]);
          if(graph[i].find(j) != graph[i].end()){
            degree--;
          }
          count = max(count, degree);
        }
      }
      return count;
    }
};
