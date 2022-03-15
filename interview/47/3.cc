#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
    int x = 0;
    int y = n - 1;
    while (x < m and y >= 0) {
      if (matrix[x][y] == target)
        return true;
      else if (matrix[x][y] < target)
        ++x;
      else
        --y;
    }
    return false;
  }
};
