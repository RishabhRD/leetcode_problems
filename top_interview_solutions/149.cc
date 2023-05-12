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
  int maxPoints(std::vector<std::vector<int>>& points) {
    ll const n = points.size();
    ll max = 0;
    for (ll i = 0; i < n; ++i) {
      auto const x0 = points[i][0];
      auto const y0 = points[i][1];
      std::map<std::pair<ll, ll>, ll> num_points;
      for (ll j = i + 1; j < n; ++j) {
        auto const x1 = points[j][0];
        auto const y1 = points[j][1];
        auto ydiff = y1 - y0;
        auto xdiff = x1 - x0;

        auto const gcd = std::gcd(std::abs(xdiff), std::abs(ydiff));
        ydiff /= gcd;
        xdiff /= gcd;

        if (ydiff < 0) {
          ydiff *= -1;
          xdiff *= -1;
        }
        if (xdiff == 0 && ydiff < 0) ydiff *= -1;
        if (ydiff == 0 && xdiff < 0) xdiff *= -1;
        ++num_points[{xdiff, ydiff}];
      }
      ll cur_max = 0;
      for (auto [k, v] : num_points) {
        cur_max = std::max(cur_max, v);
      }
      ++cur_max;
      max = std::max(max, cur_max);
    }
    return max;
  }
};
