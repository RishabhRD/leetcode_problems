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
    int removeDuplicates(vector<int>& nums) {
      return unique(begin(nums), end(nums)) - begin(nums);
    }
};
