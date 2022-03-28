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
    int missingNumber(vector<int>& nums) {
      if(find(cbegin(nums), cend(nums), 0) == cend(nums)){
        return 0;
      }
      const int n = size(nums);
      const int sum = n * (n + 1) / 2;
      return sum - accumulate(cbegin(nums), cend(nums), 0);
    }
};
