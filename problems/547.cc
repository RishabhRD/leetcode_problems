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

void dfs(vector<vector<int>>& graph, int cur_num, vector<bool>& visited){
  visited[cur_num] = true;
  for(size_t i = 0; i < size(graph[cur_num]); i++){
    if(graph[cur_num][i] and (not visited[i])){
      dfs(graph, i, visited);
    }
  }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      vector<bool> visited(size(isConnected));
      int cnt = 0;
      for(size_t i = 0; i < size(isConnected); i++){
        if(not visited[i]){
          dfs(isConnected, i, visited);
          cnt++;
        }
      }
      return cnt;
    }
};
