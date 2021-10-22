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
    void rotate(vector<vector<int>>& matrix) {
      reverse(begin(matrix), end(matrix));
      for(size_t i = 0; i < size(matrix); i++){
        for(size_t j = i + 1; j < size(matrix); j++){
          swap(matrix[i][j], matrix[j][i]);
        }
      }
    }
};
