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
  long long maxAlternatingSum(vector<int>& nums) {
    int const n = size(nums);
    auto plus = 0ll;
    auto minus = 0ll;
    for (int i = 1; i <= n; ++i) {
      auto const last_plus = plus;
      auto const last_minus = minus;
      plus = max(last_plus, last_minus + nums[i - 1]);
      minus = max(last_minus, last_plus - nums[i - 1]);
    }
    return max(plus, minus);
  }
};
