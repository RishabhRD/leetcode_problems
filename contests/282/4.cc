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
  int minimumFinishTime(vector<vector<int>>& tires, int changeTime,
                        int numLaps) {
    int const n = size(tires);
    vector without_change(n, vector(20, 2e9));
    for (int i = 0; i < size(tires); ++i) {
      without_change[i][1] = tires[i][0];
      for (int j = 2; j < 20; ++j) {
        if (static_cast<long long>(without_change[i][j - 1]) * tires[i][1] >=
            2e9) {
          break;
        }
        without_change[i][j] = without_change[i][j - 1] * tires[i][1];
      }
      for (int j = 2; j < 20; ++j) {
        if (without_change[i][j - 1] + without_change[i][j] >= 2e9) break;
        without_change[i][j] += without_change[i][j - 1];
      }
    }
    vector dp(numLaps + 1, 2e9);
    dp[1] =
        min_element(begin(tires), end(tires), [](auto const& a, auto const& b) {
          return a[0] < b[0];
        })->front();
    for (int x = 2; x <= numLaps; ++x) {
      if (x < 20) {
        for (int i = 0; i < n; ++i) {
          dp[x] = min(dp[x], without_change[i][x]);
        }
      }
      for (int j = 1; j <= 18; ++j) {
        if (x - j >= 0) dp[x] = min(dp[x], dp[j] + changeTime + dp[x - j]);
      }
    }
    return dp[numLaps];
  }
};
