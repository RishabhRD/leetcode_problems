#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int reverse_digit(int n) {
  int reverse = 0;
  int remainder = 0;
  while (n != 0) {
    remainder = n % 10;
    reverse = reverse * 10 + remainder;
    n /= 10;
  }
  return reverse;
}

class Solution {
 public:
  bool sumOfNumberAndReverse(int num) {
    for (int i = 0; i <= num; ++i) {
      if (i + reverse_digit(i) == num) return true;
    }
    return false;
  }
};
