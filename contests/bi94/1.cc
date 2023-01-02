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
  int captureForts(std::vector<int> const& forts) {
    auto const n = std::size(forts);
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
      if (forts[i] == 1) {
        {
          ll sum = 0;
          bool found = false;
          for (ll j = i + 1; j < n; ++j) {
            if (forts[j] == 0) {
              ++sum;
            }
            if (forts[j] == -1) {
              found = true;
              break;
            }
            if (forts[j] == 1) break;
          }
          if (found) {
            ans = std::max(ans, sum);
          }
        }
        {
          ll sum = 0;
          bool found = false;
          for (ll j = i - 1; j >= 0; --j) {
            if (forts[j] == 0) {
              ++sum;
            }
            if (forts[j] == -1) {
              found = true;
              break;
            }
            if (forts[j] == 1) break;
          }
          if (found) {
            ans = std::max(ans, sum);
          }
        }
      }
    }
    return ans;
  }
};
