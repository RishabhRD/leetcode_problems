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
    void moveZeroes(vector<int>& nums) {
      int pos = 0;
      for(int num : nums){
        if(num != 0)
          nums[pos++] = num;
      }
      while(pos < size(nums)){
        nums[pos++] = 0;
      }
    }
};
