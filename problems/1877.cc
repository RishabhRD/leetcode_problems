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
    int minPairSum(vector<int>& nums) {
      sort(begin(nums), end(nums));
      int max_sum = 0;
      const auto n = size(nums);
      for(size_t i = 0; i < n / 2 ; i++){
        max_sum = max(max_sum, nums[i] + nums[n - i - 1]);
      }
      return max_sum;
    }
};
