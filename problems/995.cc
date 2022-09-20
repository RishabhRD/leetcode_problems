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

bool is_flipped(int num_flipped) { return num_flipped % 2 == 1; }

bool to_flip(int num_flipped, int num) {
  bool flipped = is_flipped(num_flipped);
  if (flipped) {
    if (num == 1)
      return true;
    else
      return false;
  } else {
    if (num == 1) return false;
    return true;
  }
}

class Solution {
 public:
  int minKBitFlips(std::vector<int>& nums, int k) {
    std::queue<int> flips;
    int res = 0;
    for (int i = 0; i < std::size(nums); ++i) {
      if (to_flip(flips.size(), nums[i])) {
        flips.push(i);
        ++res;
      }
      if (not std::empty(flips) and flips.front() <= i - k + 1) {
        flips.pop();
      }
    }
    if (flips.empty()) return res;
    return -1;
  }
};
