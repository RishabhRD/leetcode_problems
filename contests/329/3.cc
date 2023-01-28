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
  bool makeStringsEqual(std::string s, std::string t) {
    ll const n = s.size();
    ll s0 = std::count(std::begin(s), std::end(s), '0');
    ll s1 = std::count(std::begin(s), std::end(s), '1');
    ll t0 = std::count(std::begin(t), std::end(t), '0');
    ll t1 = std::count(std::begin(t), std::end(t), '1');
    if (s0 == s1 && t0 == t1) return true;
    if (s0 > t0) {
      while (s0 > t0) {
        if (s1 >= 1) {
          --s0;
          ++s1;
        } else {
          break;
        }
      }
    } else {
      while (s1 > t1) {
        if (s1 >= 2) {
          --s1;
          ++s0;
        } else {
          break;
        }
      }
    }
    return s0 == t0 && s1 == t1;
  }
};
