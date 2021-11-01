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
  int divide(int dividend, int divisor) {
    if(dividend == INT32_MIN and divisor == -1) return INT32_MAX;
    return dividend / divisor;
  }
};
