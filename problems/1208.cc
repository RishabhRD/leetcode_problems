#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int equalSubstring(string s, string t, int maxCost) {
    auto const n = size(s);
    size_t i{};
    size_t max_len = 0;
    int cur_cost = 0;
    for (size_t j{}; j < n; ++j) {
      cur_cost += abs(s[j] - t[j]);
      while (cur_cost > maxCost) {
        cur_cost -= abs(s[i] - t[i]);
        ++i;
      }
      max_len = max(max_len, j - i + 1);
    }
    return max_len;
  }
};
