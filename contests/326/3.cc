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
  int minimumPartition(std::string s, int k) {
    auto const n = std::size(s);
    ll sum = 0;
    ll cur = 0;
    for (ll i = 0; i < n; ++i) {
      cur = cur * 10 + (s[i] - '0');
      if (cur > k) {
        if (cur < 10) return -1;
        --i;
        ++sum;
        cur = 0;
      }
    }
    if (cur != 0) return sum + 1;
    return sum;
  }
};
