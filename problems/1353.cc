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
  int maxEvents(std::vector<std::vector<int>>& events) {
    auto const n = std::size(events);
    std::sort(std::begin(events), std::end(events));
    constexpr static int max_day = 1e5;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int i = 0;
    int ans = 0;
    for (int day = 0; day <= max_day; ++day) {
      while (not std::empty(pq) and pq.top() < day) {
        pq.pop();
      }
      while (i < n and events[i][0] == day) {
        pq.push(events[i][1]);
        ++i;
      }
      if (not std::empty(pq)) {
        ++ans;
        pq.pop();
      }
    }
    return ans;
  }
};
