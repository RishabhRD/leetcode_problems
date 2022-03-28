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
  int singleNonDuplicate(vector<int> &nums) {
    int low = 0;
    int high = size(nums) - 1;
    while (low < high) {
      int mid = (low + high) / 2;
      if (mid % 2) mid--;
      if (nums[mid] == nums[mid + 1]) {
        low = mid + 2;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
};
