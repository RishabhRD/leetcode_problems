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
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> vec;
    for(int i = 1; i <= numRows; i++){
      vec.emplace_back(i, 1);
    }
    for(int i = 1; i < numRows; i++){
      const int n = size(vec[i]);
      for(int j = 1; j < n - 1; j++){
        vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
      }
    }
    return vec;
  }
};
