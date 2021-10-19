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
    bool canJump(vector<int>& nums) {
      size_t max_reachable = 0;
      for(size_t i = 0; i < size(nums); i++){
        max_reachable = max(max_reachable, i + nums[i]);
        if(max_reachable >= size(nums) - 1) return true;
        if(nums[i] == 0 and max_reachable <= i){
          return false;
        }
      }
      return true;
    }
};
