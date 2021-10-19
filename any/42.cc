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
    int trap(vector<int>& height) {
      size_t begin = 0;
      size_t end = size(height) - 1;
      int max_height = 0;
      int area = 0;
      while(begin < end){
        if(height[begin] < height[end]){
          max_height = max(max_height, height[begin]);
          area += (max_height -  height[begin]);
          begin++;
        }else{
          max_height = max(max_height, height[end]);
          area += (max_height - height[end]);
          end--;
        }
      }
      return area;
    }
};
