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
    void rotate(vector<int>& nums, int k) {
      k = k % size(nums);
      reverse(begin(nums), end(nums));
      reverse(begin(nums), begin(nums) + k);
      reverse(begin(nums) + k, end(nums));
    }
};
