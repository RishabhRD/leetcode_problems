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

class Solution {
public:
  int countHillValley(vector<int> &nums) {
    int const n = size(nums);
    vector<int> left_non_equal(n, -1);
    vector<int> right_non_equal(n, 101);
    for (int i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1]) {
        left_non_equal[i] = left_non_equal[i - 1];
      } else {
        left_non_equal[i] = nums[i - 1];
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] == nums[i + 1]) {
        right_non_equal[i] = right_non_equal[i + 1];
      } else {
        right_non_equal[i] = nums[i + 1];
      }
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
      if (left_non_equal[i] < 0 or right_non_equal[i] > 100) { continue; }
      if (left_non_equal[i] == left_non_equal[i - 1]) continue;
      if (left_non_equal[i] < nums[i] and right_non_equal[i] < nums[i])
        cnt++;
      else if (left_non_equal[i] > nums[i] and right_non_equal[i] > nums[i])
        cnt++;
    }
    return cnt;
  }
};
