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
  int maxProduct(vector<int> &nums) {
    int cur_prod = nums[0];
    int max_prod = nums[0];
    int min_prod = nums[0];
    for (int i = 1; i < size(nums); i++) {
      int const old_max_prod = max_prod;
      max_prod = max({ max_prod * nums[i], min_prod * nums[i], nums[i] });
      min_prod = min({ old_max_prod * nums[i], min_prod * nums[i], nums[i] });
      cur_prod = max(cur_prod, max_prod);
    }
    return cur_prod;
  }
};
