#include <cmath>
#include <cstddef>
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
  int longestSubarray(vector<int> &nums) {
    size_t i = 0, j;
    int k = 1;
    for(j = 0; j < size(nums); j++){
      if(nums[j] == 0){
        k--;
      }
      if(k < 0 and nums[i++] == 0){
        k++;
      }
    }
    return (j - i) - (k == 1 ? 0 : 1);
  }
};
