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

template<typename T, typename Integer, typename BinaryOperation>
constexpr T power_accumulate(T r, T a, Integer n, BinaryOperation op) {
  // precondition: n > 0
  while (true) {
    if (n & 1) {
      r = op(r, a);
      if (n == 1) return r;
    } else if (n == 0)
      return r;
    a = op(a, a);
    n >>= 1;
  }
}

template<typename T,
  typename Integer,
  typename BinaryOperation = std::multiplies<T>>
constexpr T power(T x, Integer n, BinaryOperation op = std::multiplies<T>{}) {
  // precondition: n > 0
  return power_accumulate(x, x, n - 1, op);
}

struct fib_matrix {
  int first;
  int second;

  constexpr fib_matrix(int first, int second)
    : first{ first }, second{ second } {}
};

auto operator*(fib_matrix x, fib_matrix y) {
  return fib_matrix{ x.first * (y.first + y.second) + x.second * y.first,
    x.first * y.first + x.second * y.second };
}

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    auto [x, y] = power(fib_matrix{ 1, 0 }, n - 2);
    return (x + y) * 2 + x;
  }
};

int main() {
  Solution sol;
  std::cout << sol.climbStairs(3) << std::endl;
}
