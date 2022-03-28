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
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
      const int n = size(grid);
      vector<int> row_max(n);
      vector<int> col_max(n);
      for(int i = 0; i < n; i++){
        row_max[i] = *max_element(cbegin(grid[i]), cend(grid[i]));
      }
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          col_max[i] = max(col_max[i], grid[j][i]);
        }
      }
      int sum = 0;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          sum += min(row_max[i], col_max[j]) - grid[i][j];
        }
      }
      return sum;
    }
};
