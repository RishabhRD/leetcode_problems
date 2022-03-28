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
  int maxProfit(vector<int> &prices) {
    int const n = size(prices);
    if (n == 1) return 0;
    auto at = [&](int const i) { return prices[i + 1] - prices[i]; };
    int dp0 = at(0) < 0 ? 0 : at(0);
    int max_sum = dp0;
    for (int i = 1; i < n - 1; i++) {
      dp0 = max(at(i), dp0 + at(i));
      max_sum = max(dp0, max_sum);
    }
    return max_sum;
  }
};
