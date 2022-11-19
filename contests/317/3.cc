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

ll sum_of_digit(ll n) {
  ll sum = 0;
  while (n > 0) {
    sum += (n % 10);
    n = n / 10;
  }
  return sum;
}

class Solution {
 public:
  long long makeIntegerBeautiful(long long n, int target) {
    ll ans = 0;
    ll cur = 1;
    while (sum_of_digit(n) > target) {
      auto const last_dig = n % 10;
      ans += cur * (10 - last_dig);
      n = n / 10;
      ++n;
      cur *= 10;
    }
    return ans;
  }
};
