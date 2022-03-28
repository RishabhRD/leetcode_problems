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

auto next(int n) {
  int sum = 0;
  while (n) {
    sum += (n % 10) * (n % 10);
    n = n / 10;
  }
  return sum;
}

class Solution {
public:
  bool isHappy(int n) {
    auto slow = n;
    auto fast = n;
    do {
      slow = next(slow);
      fast = next(next(fast));
    } while (slow != fast);
    return slow == 1;
  }
};
