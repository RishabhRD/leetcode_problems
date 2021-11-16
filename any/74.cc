#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      const int m = size(matrix);
      const int n = size(matrix[0]);
      auto ele = [&](int idx){
        // idx = i * n + j
        int i = idx / n;
        int j = idx % n;
        return matrix[i][j];
      };
      int low = 0;
      int high = m * n - 1;
      while(low <= high){
        int mid = (low + high) / 2;
        if(ele(mid) == target){
          return true;
        }else if(ele(mid) > target){
          high = mid - 1;
        }else{
          low = mid + 1;
        }
      }
      return false;
    }
};
