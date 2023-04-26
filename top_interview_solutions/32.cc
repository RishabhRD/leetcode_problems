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
  int longestValidParentheses(std::string s) {
    ll max = 0;
    std::stack<ll> idx({-1ll});
    for (ll i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        idx.push(i);
      } else {
        idx.pop();
        if (idx.size()) {
          max = std::max(max, i - idx.top());
        } else {
          idx.push(i);
        }
      }
    }
    return max;
  }
};
