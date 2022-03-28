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

int find(int u, vector<int>& parent){
  if(parent[u] == -1){
    return u;
  }
  return (parent[u] = find(parent[u], parent));
}

bool compress(int u, int v, vector<int>& parent, vector<int>& size){
  int root_u = find(u, parent);
  int root_v = find(v, parent);
  if(root_u == root_v) return false;
  if(size[root_u] > size[root_v]){
    parent[root_v] = root_u;
    size[root_u] += size[root_v];
  }else{
    parent[root_u] = root_v;
    size[root_v] += size[root_u];
  }
  return true;
}

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      vector<int> parent(size(edges) + 1, -1);
      vector<int> size_vec(size(edges) + 1, 1);
      for(const auto& edge : edges){
        if(not compress(edge[0], edge[1], parent, size_vec)){
          return {edge[0], edge[1]};
        }
      }
      return {0, 1};
    }
};
