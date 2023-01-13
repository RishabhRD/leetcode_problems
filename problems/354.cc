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

using ll = int;

class Solution {
 public:
  int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
    std::sort(std::begin(envelopes), std::end(envelopes),
              [](auto const& a, auto const& b) {
                if (a[0] == b[0])
                  return a[1] > b[1];
                else
                  return a[0] < b[0];
              });
    std::vector<ll> res;
    for (auto const& e : envelopes) {
      auto itr = std::lower_bound(std::begin(res), std::end(res), e[1]);
      if (itr == std::end(res)) {
        res.push_back(e[1]);
      } else {
        *itr = e[1];
      }
    }
    return res.size();
  }
};
