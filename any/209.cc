#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int low = 0, high = 0;
    const int n = size(nums);
    int cur_sum = 0;
    int min_len = size(nums) + 1;
    while(high < n){
      cur_sum += nums[high++];
      while(cur_sum >= target){
        min_len = min(min_len, high - low);
        cur_sum -= nums[low++];
      }
    }
    return min_len == size(nums) + 1 ? 0 : min_len;
  }
};
