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

class Solution {
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    vector distance(n, vector<int>(n));
    for(const auto& edge : edges){
      distance[edge[0]][edge[1]] = edge[2];
      distance[edge[1]][edge[0]] = edge[2];
    }
    for(int i = 0; i < n; i++) distance[i][i] = 0;
    for(int k = 0; k < n; k++){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
        }
      }
    }
    int smallest = INT32_MAX;
    int ans = 0;
    for(int i = 0; i < n; i++){
      int count = 0;
      for(int j = 0; j < n; j++){
        if(distance[i][j] <= distanceThreshold){
          count++;
        }
      }
      if(count <= smallest){
        ans = i;
        smallest = count;
      }
    }
    return ans;
  }
};
