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

int get_power(int n) {
  if (n == 1) return 0;

  if (n % 2 == 0) {
    return 1 + get_power(n / 2);
  } else {
    return 1 + get_power(3 * n + 1);
  }
}

class Solution {
 public:
  int getKth(int lo, int hi, int k) {
    std::vector dp(1001, -1);
    for (int i = 1; i <= 1000; ++i) {
      dp[i] = get_power(i);
    }
    std::vector to_sort(hi - lo + 1, 0);
    std::iota(std::begin(to_sort), std::end(to_sort), lo);
    std::nth_element(std::begin(to_sort), std::begin(to_sort) + k - 1,
                     std::end(to_sort), [&](auto a, auto b) {
                       if (dp[a] == dp[b]) {
                         return a < b;
                       } else {
                         return dp[a] < dp[b];
                       }
                     });
    return to_sort[k - 1];
  }
};
