#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    nums.push_back(0);
    int const n = size(nums);
    for (int i = 0; i < n; ++i) {
      while (nums[i] >= 0 and nums[i] < n and nums[nums[i]] != nums[i]) {
        swap(nums[nums[i]], nums[i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i) return i;
    }
    return n;
  }
};
