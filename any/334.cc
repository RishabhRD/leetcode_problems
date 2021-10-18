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
    bool increasingTriplet(const vector<int>& nums) const noexcept {
      auto small = INT32_MAX;
      auto big = INT32_MAX;
      for(const auto n : nums){
        if(small >= n) small = n;
        else if(big >= n) big = n;
        else return true;
      }
      return false;
    }
};
