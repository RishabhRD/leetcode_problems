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
  int lengthOfLIS(vector<int> const &nums) {
    vector<int> dp;
    for (int const num : nums) {
      auto itr = lower_bound(begin(dp), end(dp), num);
      if (itr == end(dp))
        dp.push_back(num);
      else
        *itr = num;
    }
    return size(dp);
  }
};
