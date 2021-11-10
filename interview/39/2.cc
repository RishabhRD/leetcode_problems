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

class union_find{
  int n;
  vector<int> parent;
  public:
  union_find(int n) : n(n), parent(n){
    for(int i = 0; i < n; i++){
      parent[i] = i;
    }
  }
  int count() const{
    return n;
  }
  void combine(int i, int j){
    int root_i = find(i);
    int root_j = find(j);
    if(root_i != root_j){
      parent[root_i] = root_j;
      n--;
    }
  }

  int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
  }
};


class Solution {
public:
  int regionsBySlashes(vector<string> &grid) {
    const int n = size(grid);
    auto idx = [&](int i, int j, int idx){
      return (i * n + j) * 4 + idx;
    };
    union_find uf(4 * n * n);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(i > 0)
          uf.combine(idx(i, j, 0), idx(i - 1, j, 2));
        if(j > 0)
          uf.combine(idx(i, j, 3), idx(i, j - 1, 1));
        if(grid[i][j] != '/'){
          uf.combine(idx(i, j, 3) , idx(i, j, 2));
          uf.combine(idx(i, j, 0) , idx(i, j, 1));
        }
        if(grid[i][j] != '\\'){
          uf.combine(idx(i, j, 0) , idx(i, j, 3));
          uf.combine(idx(i, j, 1) , idx(i, j, 2));
        }
      }
    }
    return uf.count();
  }
};
