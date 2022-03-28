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

constexpr double my_pow(double r, double a, long n) {
  while (true) {
    if (n & 1) {
      r = r * a;
      if (n == 1) return r;
    }
    a = a * a;
    n >>= 1;
  }
}

class Solution {
public:
  constexpr double myPow(double x, long n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / my_pow(1, x, -n);
    return my_pow(1, x, n);
  }
};

int main() {
  Solution sol;
  sol.myPow(2, -3);
}
