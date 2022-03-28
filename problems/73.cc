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
  void setZeroes(vector<vector<int>> &matrix) {
    auto row{ false };
    auto col{ false };
    auto const m = size(matrix);
    auto const n = size(matrix[0]);
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          if (i == 0) row = true;
          if (j == 0) col = true;
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0) matrix[i][j] = 0;
        if (matrix[0][j] == 0) matrix[i][j] = 0;
      }
    }

    if (row) {
      for (int i = 0; i < n; i++) { matrix[0][i] = 0; }
    }

    if (col) {
      for (int i = 0; i < m; i++) { matrix[i][0] = 0; }
    }
  }
};
