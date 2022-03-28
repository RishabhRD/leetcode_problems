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
  int trap(vector<int> &height) {
    int max_height = 0;
    int low = 0;
    int high = size(height) - 1;
    int area = 0;
    while (low <= high) {
      if (height[low] < height[high]) {
        max_height = max(max_height, height[low]);
        area += max_height - height[low];
        low++;
      } else {
        max_height = max(max_height, height[high]);
        area += max_height - height[high];
        high--;
      }
    }
    return area;
  }
};
