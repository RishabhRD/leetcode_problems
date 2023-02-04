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
  int maxCount(std::vector<int>& banned, int n, int maxSum) {
    std::unordered_set<int> st{std::begin(banned), std::end(banned)};
    ll cur_sum = 0;
    ll count = 0;
    for (ll i = 1; i <= n; ++i) {
      if (cur_sum + i <= maxSum && !st.count(i)) {
        cur_sum += i;
        ++count;
      }
    }
    return count;
  }
};
