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

ll digit_sum(ll n) {
  ll sum = 0;
  while (n > 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}

class Solution {
 public:
  int differenceOfSum(std::vector<int>& nums) {
    auto const sum = std::accumulate(std::begin(nums), std::end(nums), 0ll);
    auto const sum2 = std::accumulate(
        std::begin(nums), std::end(nums), 0ll,
        [](auto prev, auto cur) { return prev + digit_sum(cur); });
    return std::abs(sum - sum2);
  }
};
