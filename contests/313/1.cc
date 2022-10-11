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

auto factors(int a) {
  std::unordered_set<int> res;
  for (int i = 1; i <= a; ++i) {
    if (a % i == 0) {
      res.insert(i);
    }
  }
  return res;
}

class Solution {
 public:
  int commonFactors(int a, int b) {
    auto const fa = factors(a);
    auto const fb = factors(b);
    int ans = 0;
    for (auto x : fa) {
      if (fb.find(x) != fb.end()) {
        ++ans;
      }
    }
    return ans;
  }
};
