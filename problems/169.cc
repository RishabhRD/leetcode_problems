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
  int majorityElement(vector<int> &nums) {
    int cnt = 1;
    int voted = nums[0];
    for (int i = 1; i < size(nums); i++) {
      if (voted == nums[i])
        cnt++;
      else {
        --cnt;
        if (cnt == 0) {
          cnt = 1;
          voted = nums[i];
        }
      }
    }
    return voted;
  }
};
