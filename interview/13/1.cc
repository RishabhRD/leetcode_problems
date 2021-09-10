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
  int singleNumber(vector<int> &nums) {
    return accumulate(
      cbegin(nums), cend(nums), 0, [](int a, int b) { return a ^ b; });
  }
};
