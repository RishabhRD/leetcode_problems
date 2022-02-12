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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int const m = size(matrix);
    int const n = size(matrix[0]);
    int i = 0;
    int j = n - 1;
    while (i < m and j >= 0) {
      if (target > matrix[i][j]) {
        i = i + 1;
      } else if (target < matrix[i][j]) {
        j = j - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
