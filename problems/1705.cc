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
  int eatenApples(std::vector<int>& apples, std::vector<int>& days) {
    auto const n = std::size(days);
    for (int i = 0; i < n; ++i) days[i] += i;

    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    int num_eaten = 0;
    for (int i = 0; i < n; ++i) {
      // push step
      if (apples[i] != 0) {
        pq.push({days[i], apples[i]});
      }

      // pop step
      while (not std::empty(pq) and pq.top().first == i) {
        pq.pop();
      }

      // eat step
      if (not std::empty(pq)) {
        auto [day_expire, num_apples] = pq.top();
        pq.pop();
        ++num_eaten;
        if (num_apples - 1 > 0) pq.push({day_expire, num_apples - 1});
      }
    }
    int i = n;
    while (not std::empty(pq)) {
      // pop apple
      while (not std::empty(pq) and pq.top().first == i) {
        pq.pop();
      }

      // eat apple
      if (not std::empty(pq)) {
        auto [day_expire, num_apples] = pq.top();
        pq.pop();
        ++num_eaten;
        if (num_apples - 1 > 0) pq.push({day_expire, num_apples - 1});
      }
      ++i;
    }
    return num_eaten;
  }
};
