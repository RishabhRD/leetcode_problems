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

auto find_factors(ll n) {
  ll factor_sum = 0;
  ll i = 2;
  while (i * i <= n) {
    if (n % i)
      ++i;
    else {
      n /= i;
      factor_sum += i;
    }
  }
  factor_sum += n;
  return factor_sum;
}

int smallest_value(int n) {
  while (true) {
    auto const factor_sum = find_factors(n);

    if (factor_sum == n) break;
    n = factor_sum;
  }
  return n;
}

class Solution {
 public:
  int smallestValue(int n) { return smallest_value(n); }
};
