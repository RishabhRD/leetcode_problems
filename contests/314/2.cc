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

class Solution {
 public:
  std::vector<int> findArray(std::vector<int>& pref) {
    auto const n = std::size(pref);
    std::vector<int> res(n, 0);
    res[0] = pref[0];
    for (int i = 1; i < n; ++i) {
      res[i] = pref[i] ^ pref[i - 1];
    }
    return res;
  }
};
