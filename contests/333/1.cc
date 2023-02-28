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
  int minOperations(int n) {
    std::queue<ll> q;
    std::unordered_set<ll> visited;
    q.push(n);
    visited.insert(n);
    ll cur_level = 0;
    while (not q.empty()) {
      auto sz = q.size();
      while (sz--) {
        auto const top = q.front();
        q.pop();
        if (top == 0) return cur_level;
        std::bitset<32> bs(top);
        for (ll i = 0; i < 32; ++i) {
          if (bs[i]) {
            ll const first = top + (1 << i);
            ll const second = top - (1 << i);
            if (!visited.count(first)) {
              q.push(first);
              visited.insert(first);
            }
            if (!visited.count(second)) {
              q.push(second);
              visited.insert(second);
            }
            break;
          }
        }
      }
      ++cur_level;
    }
    return cur_level;
  }
};
