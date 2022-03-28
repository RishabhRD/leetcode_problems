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
  void moveZeroes(vector<int> &nums) {
    stable_partition(begin(nums), end(nums), [](int num) { return num != 0; });
  }
};
