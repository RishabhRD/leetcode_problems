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
    void setZeroes(vector<vector<int>>& matrix) {
      bool row = false, col = false;
      for(int i = 0; i < size(matrix); i++){
        for(int j = 0; j < size(matrix[0]); j++){
          if(matrix[i][j] == 0){
            if(i == 0){
              row = true;
            }
            if(j == 0){
              col = true;
            }
            matrix[i][0] = matrix[0][j] = 0;
          }
        }
      }
      for(int i = 1; i < size(matrix); i++){
        for(int j = 1; j < size(matrix[0]); j++){
          if(matrix[i][0] == 0 or matrix[0][j] == 0) matrix[i][j] = 0;
        }
      }
      if(row){
        for(int i = 0; i < size(matrix[0]); i++){
          matrix[0][i] = 0;
        }
      }
      if(col){
        for(int i = 0; i < size(matrix); i++){
          matrix[i][0] = 0;
        }
      }
    }
};
