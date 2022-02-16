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
  bool increasingTriplet(const vector<int> &nums) const noexcept {
    auto small = INT32_MAX;
    auto big = INT32_MAX;
    for (auto const num : nums) {
      if (num <= small)
        small = num;
      else if (num > small and num <= big)
        big = num;
      else
        return true;
    }
    return false;
  }
};
