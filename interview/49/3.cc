#include <optional>
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

bool subset_sum(vector<int> &nums, int sum, int req_len) {
  int const n = size(nums);
  vector dp(sum + 1, pair{ false, 0 });
  dp[0] = { true, 1 };
  for (int num : nums) {
    for (int j = sum; j >= 0; j--) {
      if (j - num >= 0) {
        if (dp[j - num].first) { dp[j] = dp[j - num]; }
      }
    }
    if (dp[sum].first and dp[sum].second == req_len) return true;
  }
  return false;
}

class Solution {
public:
  bool splitArraySameAverage(vector<int> &nums) {
    int const sum = accumulate(begin(nums), end(nums), 0);
    int const n = size(nums);
    for (int i = 1; i < n; i++) {
      if ((sum * i) % n == 0) {
        if (subset_sum(nums, (sum * i) / n, i)) {
          cout << sum << ' ' << i << ' ' << n << ' ' << ((sum * i) / n) << endl;
          return true;
        }
      }
    }
    return false;
  }
};
