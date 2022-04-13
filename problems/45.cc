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

class Solution {
 public:
  int jump(vector<int>& nums) {
    int const n = size(nums);
    int max_reachable = 0;
    int last_jumped_pos = 0;
    int jumps = 0;
    int i = 0;
    while (last_jumped_pos < n - 1) {
      max_reachable = max(max_reachable, i + nums[i]);
      if (i == last_jumped_pos) {
        ++jumps;
        last_jumped_pos = max_reachable;
      }
      ++i;
    }
    return jumps;
  }
};
