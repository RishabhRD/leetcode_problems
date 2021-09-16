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
    if(size(prices) < 2) return 0;
    int max_so_far = 0;
    int price_so_far = 0;
    for(int i = 1; i < size(prices); i++){
      int diff = prices[i] - prices[i - 1];
      price_so_far = max(0, diff + price_so_far);
      max_so_far = max(max_so_far, price_so_far);
    }
    return max_so_far;
  }
};
