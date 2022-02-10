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
  int maxSubArray(vector<int> &nums) {
    int last_sum = nums[0];
    int max_sum = last_sum;
    for (int i = 1; i < size(nums); i++) {
      last_sum = max(last_sum + nums[i], nums[i]);
      max_sum = max(last_sum, max_sum);
    }
    return max_sum;
  }
};
