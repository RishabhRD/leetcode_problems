#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    auto at = [&](int i) -> long {
      if (i >= 0 and i < size(nums)) return nums[i];
      return INT32_MIN;
    };
    int low = 0;
    int high = size(nums) - 1;
    while (low < high) {
      int mid = (low + high) / 2;
      if (at(mid) > at(mid + 1)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};
