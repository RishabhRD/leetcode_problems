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
  int bestClosingTime(std::string customers) {
    std::vector<int> ys;
    {
      int num_y = 0;
      for (auto c : customers) {
        if (c == 'Y') ++num_y;
        ys.push_back(num_y);
      }
    }

    std::vector<int> ns;
    {
      int num_n = 0;
      for (auto c : customers) {
        if (c == 'N') ++num_n;
        ns.push_back(num_n);
      }
    }

    auto const num_y = [&](auto a, auto b) {
      if (b < a) return 0;
      if (a == 0) return ys[b];
      return ys[b] - ys[a - 1];
    };

    auto const num_n = [&](auto a, auto b) {
      if (b < a) return 0;
      if (a == 0) return ns[b];
      return ns[b] - ns[a - 1];
    };

    auto const n = std::size(customers);
    int min_cost = INT32_MAX;
    int min_hour = -1;
    for (int i = 0; i <= n; ++i) {
      auto cur_cost = num_n(0, i - 1) + num_y(i, n - 1);
      if (min_cost > cur_cost) {
        min_cost = cur_cost;
        min_hour = i;
      }
    }
    return min_hour;
  }
};
