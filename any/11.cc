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
    int maxArea(vector<int>& height) {
      size_t i = 0, j = size(height) - 1;
      size_t max_area = 0;
      while(i < j){
        max_area = max(max_area, (j - i) * min(height[i], height[j]));
        if(height[i] < height[j]){
          i++;
        }else{
          j--;
        }
      }
      return max_area;
    }
};
