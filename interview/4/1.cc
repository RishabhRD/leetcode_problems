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
    int maxProfit(vector<int>& prices) {
      int max_cur = 0;
      int max_so_far = 0;
      for(int i = 1; i < size(prices); i++){
        max_cur = max(0, max_cur += prices[i] - prices[i - 1]);
        max_so_far = max(max_so_far, max_cur);
      }
      return max_so_far;
    }
};
