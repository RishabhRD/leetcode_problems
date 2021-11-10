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
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    const int m = size(matrix);
    const int n = size(matrix[0]);
    for(int j = 0; j < n; j++){
      int x = 0;
      int y = j;
      int k = min(m, n - y);
      int ele = matrix[x][y];
      for(int i = 0; i < k; i++){
        if(matrix[i + x][i + y] != ele) return false;
      }
    }
    for(int i = 1; i < m; i++){
      int x = i;
      int y = 0;
      int k = min(n, m - x);
      int ele = matrix[x][y];
      for(int i = 0; i < k; i++){
        if(matrix[i + x][i + y] != ele) return false;
      }
    }
    return true;
  }
};
