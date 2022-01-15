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
    int max_sum = nums[0];
    int storage = nums[0];
    for (int i = 1; i < size(nums); i++) {
      storage = max(storage + nums[i], nums[i]);
      max_sum = max(max_sum, storage);
    }
    return max_sum;
  }
};
