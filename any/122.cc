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
    int profit = 0;
    const int n = size(prices);
    for (int i = 0; i < n - 1; i++) {
      if (prices[i + 1] > prices[i]) profit += prices[i + 1] - prices[i];
    }
    return profit;
  }
};
