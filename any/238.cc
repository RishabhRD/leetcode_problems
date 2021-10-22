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
    vector<int> productExceptSelf(const vector<int>& nums) {
      vector<int> res(size(nums));
      for(int i = 0, tmp = 1; i < size(nums); i++){
        res[i] = tmp;
        tmp *= nums[i];
      }
      for(int i = size(nums) - 1, tmp = 1; i >= 0; i--){
        res[i] *= tmp;
        tmp *= nums[i];
      }
      return res;
    }
};
