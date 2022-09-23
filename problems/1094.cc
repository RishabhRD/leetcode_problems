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
  bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
    std::sort(std::begin(trips), std::end(trips),
              [](auto const& a, auto const& b) { return a[1] < b[1]; });

    auto cmp = [&](auto a, auto b) { return trips[a][2] > trips[b][2]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);

    int cur_passengers = 0;
    for (int i = 0; i < std::size(trips); ++i) {
      while (not std::empty(pq) and trips[pq.top()][2] <= trips[i][1]) {
        cur_passengers -= trips[pq.top()][0];
        pq.pop();
      }
      pq.push(i);
      cur_passengers += trips[i][0];
      if (cur_passengers > capacity) return false;
    }
    return true;
  }
};
