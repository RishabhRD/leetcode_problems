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
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

constexpr int num_steps(int n) noexcept {
  int count = 0;
  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      if (n == 3 or n % 4 == 1) {
        --n;
      } else {
        ++n;
      }
    }
    ++count;
  }
  return count;
}

class Solution {
 public:
  constexpr int integerReplacement(int n) const noexcept {
    if (n == INT32_MAX) return 32;
    return num_steps(n);
  }
};
