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
  int closetTarget(std::vector<std::string>& words, std::string target,
                   int startIndex) {
    auto const n = std::size(words);
    ll d = INT32_MAX;
    {
      ll cur_d = 0;
      ll i = startIndex;
      do {
        if (words[i] == target) {
          d = std::min(d, cur_d);
        }
        ++cur_d;
        i = (i + 1) % n;
      } while (i != startIndex);
    }
    {
      ll cur_d = 0;
      ll i = startIndex;
      do {
        if (words[i] == target) {
          d = std::min(d, cur_d);
        }
        ++cur_d;
        i = (i - 1 + n) % n;
      } while (i != startIndex);
    }
    if (d == INT32_MAX) return -1;
    return d;
  }
};
