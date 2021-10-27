#include <unordered_map>
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
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mp;
    vector<int> res(2);
    for (int i = 0; i < size(nums); i++) {
      if (mp.find(target - nums[i]) != mp.end()) {
        res[1] = i;
        res[0] = mp[target - nums[i]];
      }
      mp[nums[i]] = i;
    }
    return res;
  }
};
