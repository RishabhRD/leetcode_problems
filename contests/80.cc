#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    ll const n = std::size(nums);
    ll i = 1;
    ll counter = 1;
    ll cur = nums[0];
    ll len = 1;
    while (i < n) {
      if (nums[i] < cur) {
        if (i + len - 1 >= n) break;
        std::swap(nums[i], nums[i + len - 1]);
        continue;
      } else if (cur == nums[i]) {
        ++counter;
      } else {
        counter = 1;
        cur = nums[i];
      }
      if (counter > 2) {
        ++len;
        if (i + len - 1 >= n) {
          break;
        }
        std::swap(nums[i], nums[i + len - 1]);
      } else {
        ++i;
      }
    }
    return n - len;
  }
};
