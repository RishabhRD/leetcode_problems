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
  int removeDuplicates(vector<int> &nums) {
    int cnt = 0;
    for (int i = 1; i < size(nums); i++) {
      if (nums[i] == nums[i - 1])
        cnt++;
      else
        nums[i - cnt] = nums[i];
    }
    return size(nums) - cnt;
  }
};
