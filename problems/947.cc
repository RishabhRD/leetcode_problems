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

void dfs(const vector<vector<int>>& stones, const vector<int>& stone, vector<vector<bool>>& visited){
  visited[stone[0]][stone[1]] = true;
  for(const auto& neigh : stones){
    if(not visited[neigh[0]][neigh[1]]){
      if(stone[0] == neigh[0] or stone[1] == neigh[1]){
        dfs(stones, neigh, visited);
      }
    }
  }
}

int count_stones(const vector<vector<int>>& stones){
  int mx = 0;
  for(const auto& stone : stones){
    mx = max(mx, stone[0]);
    mx = max(mx, stone[1]);
  }
  return mx + 1;
}

class Solution {
public:
  int removeStones(vector<vector<int>> &stones) {
    int n = count_stones(stones);
    vector visited(n, vector<bool>(n));
    int num_islands = 0;
    for(const auto& stone : stones){
      if(not visited[stone[0]][stone[1]]){
        dfs(stones, stone, visited);
        num_islands++;
      }
    }
    return size(stones) - num_islands;
  }
};
