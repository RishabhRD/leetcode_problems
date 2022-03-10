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

constexpr int my_abs(int n) {
  if (n < 0)
    return -n;
  else
    return n;
}

class Solution {
public:
  constexpr double myPow(double x, int n) {
    int abs_n = my_abs(n);
    double ans = 1;
    while (abs_n > 0) {
      if (abs_n & 1) ans *= x;
      abs_n >>= 1;
      x *= x;
    }
    return n >= 0 ? ans : (1 / ans);
  }
};

int main() {
  Solution sol;
  constexpr int x = sol.myPow(2, 3);
}
