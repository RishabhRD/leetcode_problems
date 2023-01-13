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
  long long appealSum(std::string s) {
    std::vector<ll> prev(26, -1);
    auto const n = s.size();
    ll res = 0;
    ll cur = 0;
    for (ll i = 0; i < n; ++i) {
      cur = cur + (i - prev[s[i] - 'a']);
      prev[s[i] - 'a'] = i;
      res += cur;
    }
    return res;
  }
};
