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
  int mySqrt(int x) {
    long long low = 0;
    long long high = x;
    while (low < high) {
      long long const mid = (low + high + 1) / 2;
      auto const res = mid * mid;
      if (res == x)
        return mid;
      else if (res > x)
        high = mid - 1;
      else
        low = mid;
    }
    return low;
  }
};
