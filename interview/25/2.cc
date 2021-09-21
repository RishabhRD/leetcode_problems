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
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
      const auto m = size(rowSum);
      const auto n = size(colSum);
      vector matrix(m, vector<int>(n));
      for(size_t i = 0; i < m; i++){
        for(size_t j = 0; j < n; j++){
          matrix[i][j] = min(rowSum[i], colSum[j]);
          rowSum[i] -= matrix[i][j];
          colSum[j] -= matrix[i][j];
        }
      }
      return matrix;
    }
};
