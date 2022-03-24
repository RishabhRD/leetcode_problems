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
  int maximumTop(vector<int> &nums, int k) {
    if (k == 0) return nums.front();
    int const n = size(nums);
    if (n == 1 and k % 2) return -1;
    auto end_itr = min(begin(nums) + k - 1, end(nums));
    auto const max_k_ele = accumulate(
      begin(nums), end_itr, -1, [](auto a, auto b) { return max(a, b); });
    auto const kth_ele = k < n ? nums[k] : -1;
    return max(max_k_ele, kth_ele);
  }
};

int main() {
  Solution sol;
  vector<int> nums{ 94,
    23,
    58,
    92,
    3,
    63,
    68,
    43,
    8,
    97,
    54,
    11,
    63,
    55,
    73,
    38,
    22,
    80,
    45,
    43,
    25,
    34,
    67,
    76,
    80,
    9,
    30,
    27,
    50,
    7,
    57,
    63,
    63,
    27,
    46,
    1,
    50,
    55,
    99,
    92,
    73,
    9,
    57,
    25,
    59,
    54,
    100,
    56,
    64,
    94,
    99 };
  cout << size(nums) << endl;
  cout << sol.maximumTop(nums, 97) << endl;
}
