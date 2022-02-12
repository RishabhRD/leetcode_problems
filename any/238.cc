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
  vector<int> productExceptSelf(const vector<int> &nums) {
    int const n = size(nums);
    vector res(n, 1);
    int left_mul = 1;
    for (int i = 0; i < n; i++) {
      res[i] *= left_mul;
      left_mul *= nums[i];
    }
    int right_mul = 1;
    for (int i = n - 1; i >= 0; i--) {
      res[i] *= right_mul;
      right_mul *= nums[i];
    }
    return res;
  }
};
