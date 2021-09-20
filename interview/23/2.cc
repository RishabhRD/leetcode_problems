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
      const int n = size(nums);
      int i = 0;
      for(int reach = 0; i < n and i <= reach; i++){
        reach = max(reach, i + nums[i]);
      }
      return i == n;
    }
};
