#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int atmost_k(vector<int> const& nums, int k) {
  int const n = size(nums);
  int i = 0;
  int j = 0;
  unordered_map<int, int> mp;
  int res = 0;
  while (j < n) {
    ++mp[nums[j]];
    while (size(mp) > k) {
      --mp[nums[i]];
      if (mp[nums[i]] == 0) mp.erase(nums[i]);
      ++i;
    }
    ++j;
    res += j - i;
  }
  return res;
}

class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atmost_k(nums, k) - atmost_k(nums, k - 1);
  }
};
