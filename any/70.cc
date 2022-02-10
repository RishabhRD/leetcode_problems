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
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int first = 1;
    int second = 2;
    for (int i = 3; i <= n; i++) {
      int new_res = first + second;
      first = second;
      second = new_res;
    }
    return second;
  }
};
