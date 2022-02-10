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
  void sortColors(vector<int> &nums) {
    int const n = size(nums);
    int zero_idx = 0;
    int two_idx = n - 1;
    for (int i = 0; i < n; i++) {
      while (nums[i] == 2 and two_idx > i) swap(nums[i], nums[two_idx--]);
      while (nums[i] == 0 and zero_idx < i) swap(nums[i], nums[zero_idx++]);
    }
  }
};
