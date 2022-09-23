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
  std::string longestDiverseString(int a, int b, int c) {
    std::priority_queue<std::pair<int, char>> pq;
    if (a) pq.push({a, 'a'});
    if (b) pq.push({b, 'b'});
    if (c) pq.push({c, 'c'});
    std::string res;
    while (pq.size() > 1) {
      auto [f_n, f_c] = pq.top();
      pq.pop();
      auto [s_n, s_c] = pq.top();
      pq.pop();
      if (f_n >= 2) {
        res += f_c;
        res += f_c;
        f_n -= 2;
      } else {
        res += f_c;
        f_n -= 1;
      }
      if (s_n >= 2 and s_n >= f_n) {
        res += s_c;
        res += s_c;
        s_n -= 2;
      } else {
        res += s_c;
        s_n -= 1;
      }
      if (f_n > 0) pq.push({f_n, f_c});
      if (s_n > 0) pq.push({s_n, s_c});
    }
    if (pq.size() > 0) {
      res += pq.top().second;
      if (pq.top().first >= 2) {
        res += pq.top().second;
      }
    }
    return res;
  }
};
