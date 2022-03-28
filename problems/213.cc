#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

int robber(vector<int> &nums, int low, int high) {
  int const n = size(nums);
  int pre = 0;
  int cur = 0;
  for (int i = low; i <= high; i++) {
    int const new_ans = max(pre + nums[i], cur);
    pre = cur;
    cur = new_ans;
  }
  return cur;
}

class Solution {
public:
  int rob(vector<int> &nums) {
    int const n = size(nums);
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
  }
};
