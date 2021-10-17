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

int atmost(vector<int> &nums, int k) {
  const int n = size(nums);
  int i = 0;
  int res = 0;
  for (int j = 0; j < n; j++) {
    k -= nums[j];
    while(k < 0){
      k += nums[i++];
    }
    res += (j - i + 1);
  }
  return res;
}

class Solution {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    if(goal == 0)
      return atmost(nums, goal);
    return atmost(nums, goal) - atmost(nums, goal - 1);
  }
};
