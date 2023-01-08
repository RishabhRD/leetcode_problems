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
  bool isItPossible(std::string word1, std::string word2) {
    std::array<ll, 26> cnt1 = {0};
    std::array<ll, 26> cnt2 = {0};
    for (auto c : word1) ++cnt1[c - 'a'];
    for (auto c : word2) ++cnt2[c - 'a'];
    auto const d1 = std::count_if(std::begin(cnt1), std::end(cnt1),
                                  [](auto n) { return n; });
    auto const d2 = std::count_if(std::begin(cnt2), std::end(cnt2),
                                  [](auto n) { return n; });
    for (ll c1 = 0; c1 < 26; ++c1) {
      for (ll c2 = 0; c2 < 26; ++c2) {
        if (cnt1[c1] == 0 || cnt2[c2] == 0) continue;
        auto new_d1 = d1;
        if (c1 != c2) {
          if (cnt1[c2] == 0) ++new_d1;
          if (cnt1[c1] == 1) --new_d1;
        }
        auto new_d2 = d2;
        if (c1 != c2) {
          if (cnt2[c1] == 0) ++new_d2;
          if (cnt2[c2] == 1) --new_d2;
        }
        if (new_d1 == new_d2) {
          return true;
        }
      }
    }
    return false;
    // if (d1 == d2 + 1 || d2 == d1 + 1) {
    //   return (std::find_if(std::begin(cnt1), std::end(cnt1),
    //                        [](auto n) { return n > 1; }) != std::end(cnt1))
    //                        &&
    //          (std::find_if(std::begin(cnt2), std::end(cnt2),
    //                        [](auto n) { return n > 1; }) != std::end(cnt2));
    // } else if (d1 == d2) {

    // }
    // return false;
  }
};
