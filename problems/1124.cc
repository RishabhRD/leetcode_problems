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

auto score(int x) {
  if (x > 8)
    return 1;
  else
    return -1;
}

class Solution {
 public:
  int longestWPI(std::vector<int>& hours) {
    auto const n = std::size(hours);
    int sum = 0;
    std::unordered_map<int, int> mp;
    int max_len = 0;
    for (int i = 0; i < n; ++i) {
      sum += score(hours[i]);
      if (mp.find(sum) == mp.end()) {
        mp[sum] = i;
      }
      if (sum > 0) {
        max_len = i + 1;
      } else {
        if (mp.find(sum - 1) != mp.end()) {
          max_len = std::max(max_len, i - mp[sum - 1]);
        }
      }
    }
    return max_len;
  }
};
