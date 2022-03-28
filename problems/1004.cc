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
  int longestOnes(vector<int> &nums, int k) {
    size_t i = 0;
    size_t j;
    for(j = 0; j < size(nums); j++){
      if(nums[j] == 0) k--;
      if(k < 0 and nums[i++] == 0) k++;
    }
    return j - i;
  }
};
