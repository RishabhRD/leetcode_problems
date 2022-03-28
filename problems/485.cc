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
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int cur_ones = 0;
      int max_ones = 0;
      for(int i : nums){
        if(i == 1){
          cur_ones++;
        }else{
          cur_ones = 0;
        }
        max_ones = max(max_ones, cur_ones);
      }
      return max_ones;
    }
};
