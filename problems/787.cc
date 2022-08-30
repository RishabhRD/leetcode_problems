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
  int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src,
                        int dst, int k) {
    std::vector<long> dist(n, INT32_MAX);
    dist[src] = 0;
    auto const max_iterations = std::min(k + 1, n);
    for (int i = 0; i < max_iterations; ++i) {
      auto cur_dist_state = dist;
      for (auto const& flight : flights) {
        auto const cur_src = flight[0];
        auto const cur_dst = flight[1];
        auto const weight = flight[2];
        cur_dist_state[cur_dst] =
            std::min(cur_dist_state[cur_dst], dist[cur_src] + weight);
      }
      dist = std::move(cur_dist_state);
    }
    if (dist[dst] == INT32_MAX) return -1;
    return dist[dst];
  }
};
