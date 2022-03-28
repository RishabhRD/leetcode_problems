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

int at_most(vector<int> &nums, int k) {
  size_t i = 0;
  size_t res = 0;
  for (size_t j = 0; j < size(nums); j++) {
    k -= nums[j] % 2;
    while (k < 0) k += nums[i++] % 2;
    res += (j - i + 1);
  }
  return res;
}

class Solution {
public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    return at_most(nums, k) - at_most(nums, k - 1);
  }
};
