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
  int maxProfit(vector<int> &prices) {
    int const n = size(prices);

    vector left(n, 0);
    int left_min = prices[0];
    for (int i = 1; i < n; i++) {
      left[i] = max(left[i - 1], prices[i] - left_min);
      left_min = min(left_min, prices[i]);
    }

    vector right(n, 0);
    int right_max = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      right[i] = max(right[i + 1], right_max - prices[i]);
      right_max = max(right_max, prices[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) { res = max(res, left[i] + right[i]); }
    return res;
  }
};
