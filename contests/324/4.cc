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

ll level(ll n) {
  ll sum = 0;
  while (n != 1) {
    n /= 2;
    ++sum;
  }
  return sum;
}

ll decrease_level(ll n, ll k) {
  while (k--) {
    n = n / 2;
  }
  return n;
}

class Solution {
 public:
  std::vector<int> cycleLengthQueries(int n,
                                      std::vector<std::vector<int>>& queries) {
    std::vector<int> ans;
    for (auto const& query : queries) {
      ll x = query[0];
      ll y = query[1];
      auto const levelx = level(x);
      auto const levely = level(y);
      // std::cout << x << ' ' << y << ' ' << levelx << ' ' << levely <<
      // std::endl;
      ll sum = 0;
      if (levelx > levely) {
        x = decrease_level(x, levelx - levely);
        sum += levelx - levely;
      } else {
        y = decrease_level(y, levely - levelx);
        sum += levely - levelx;
      }
      while (x != y) {
        x = x / 2;
        y = y / 2;
        sum += 2;
      }
      ans.push_back(sum + 1);
    }
    return ans;
  }
};
