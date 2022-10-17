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
  std::vector<int> productQueries(int n,
                                  std::vector<std::vector<int>>& queries) {
    constexpr static int mod = 1e9 + 7;
    std::vector<int> powers;
    std::bitset<32> bs(n);
    for (int i = 0; i < 32; ++i) {
      if (bs[i]) powers.push_back(i);
    }
    std::vector<int> ps(std::size(powers));
    std::partial_sum(std::begin(powers), std::end(powers), std::begin(ps));
    auto range_sum = [&](int i, int j) {
      if (i == 0) {
        return ps[j];
      } else {
        return ps[j] - ps[i - 1];
      }
    };
    std::vector<long long> power_2(497);
    long long cur_power = 1;
    for (int i = 0; i < 497; ++i) {
      power_2[i] = cur_power;
      cur_power = (cur_power * 2) % mod;
    }

    std::vector<int> res;
    for (auto const& query : queries) {
      auto const power = range_sum(query[0], query[1]);
      res.push_back(power_2[power]);
    }
    return res;
  }
};
