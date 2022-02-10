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
  int firstMissingPositive(vector<int> &nums) {
    int const n = size(nums);
    nums.push_back(0);
    for (int &num : nums) {
      if (num < 0 || num > n) num = 0;
    }
    for (int i = 0; i <= n; i++) {
      while (i != nums[i] and nums[i] != nums[nums[i]]) {
        swap(nums[i], nums[nums[i]]);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (nums[i] != i) return i;
    }
    return n + 1;
  }
};
