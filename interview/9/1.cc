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
  int countNegatives(vector<vector<int>> &grid) {
    int m = size(grid);
    int n = size(grid[0]);
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] < 0) cnt++;
      }
    }
    return cnt;
  }
};
