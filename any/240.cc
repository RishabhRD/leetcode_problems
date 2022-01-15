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
    const int m = size(matrix);
    const int n = size(matrix[0]);
    int cur_x = 0;
    int cur_y = n - 1;
    while(cur_x < m and cur_y >= 0){
      if(matrix[cur_x][cur_y] == target) return true;
      else if(target > matrix[cur_x][cur_y]) cur_x++;
      else if(target < matrix[cur_x][cur_y]) cur_y--;
    }
    return false;
  }
};
