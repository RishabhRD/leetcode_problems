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
  int balancedString(std::string s) {
    auto const n = std::size(s);
    auto const k = n / 4;
    std::array<int, 128> count = {0};
    for (auto c : s) ++count[c];

    int ans = n;
    int low = 0;
    for (int high = 0; high < n; ++high) {
      --count[s[high]];
      while (low < n and count['Q'] <= k and count['W'] <= k and
             count['E'] <= k and count['R'] <= k) {
        ans = std::min(ans, high - low + 1);
        ++count[s[low]];
        ++low;
      }
    }
    return ans;
  }
};
