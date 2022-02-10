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
  double myPow(double x, int n) {
    double res = 1;
    for (; n; n /= 2) {
      if (n & 1) {
        if (n > 0)
          res *= x;
        else
          res /= x;
      }
      x *= x;
    }
    return res;
  }
};
