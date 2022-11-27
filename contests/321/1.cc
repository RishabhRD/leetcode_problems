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
  int pivotInteger(int n) {
    for (int i = 1; i <= n; ++i) {
      int sum = 0;
      for (int j = 1; j <= i; ++j) {
        sum += j;
      }
      int sum1 = 0;
      for (int j = i; j <= n; ++j) {
        sum1 += j;
      }
      if (sum == sum1) return i;
    }
    return -1;
  }
};
