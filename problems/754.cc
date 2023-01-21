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
  int reachNumber(int target) {
    target = std::abs(target);
    ll sum = 0;
    ll step = 0;
    ll i = 1;
    for (ll i = 1; sum < target || (sum - target) % 2 == 1; ++i) {
      sum += i;
      ++step;
    }
    return step;
  }
};
