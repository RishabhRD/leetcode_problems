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
  int alternateDigitSum(int n) {
    std::vector<ll> digits;
    while (n) {
      digits.push_back(n % 10);
      n = n / 10;
    }
    std::reverse(std::begin(digits), std::end(digits));
    ll sum = 0;
    bool is_positive = true;
    for (auto n : digits) {
      if (is_positive) {
        sum += n;
      } else {
        sum -= n;
      }
      is_positive = !is_positive;
    }
    return sum;
  }
};
