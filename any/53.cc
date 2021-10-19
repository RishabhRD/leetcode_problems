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
    int maxSubArray(vector<int>& nums) {
      int cur_sum = 0;
      int max_sum = 0;
      size_t count_neg = 0;
      int max_ele = INT32_MIN;
      for(auto n : nums){
        if(n < 0) count_neg++;
        cur_sum += n;
        max_ele = max(max_ele, n);
        cur_sum = max(cur_sum, 0);
        max_sum = max(cur_sum, max_sum);
      }
      return count_neg == size(nums) ? max_ele : max_sum;
    }
};
