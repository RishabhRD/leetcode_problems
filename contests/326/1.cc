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

using ll = long long;

class Solution {
 public:
  int countDigits(int num) {
    ll const n = num;
    ll sum = 0;
    while (num > 0) {
      auto const d = num % 10;
      if (d != 0 && n % d == 0) {
        ++sum;
      }
      num = num / 10;
    }
    return sum;
  }
};
