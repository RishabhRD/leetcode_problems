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
  bool canJump(vector<int> &nums) {
    int last_position = size(nums) - 1;
    for (int i = last_position - 1; i >= 0; i--) {
      if (i + nums[i] >= last_position) last_position = i;
    }
    return last_position == 0;
  }
};
