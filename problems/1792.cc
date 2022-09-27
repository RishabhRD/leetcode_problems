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

auto change(double a, double b) { return ((a + 1) / (b + 1)) - (a / b); }

using tii = std::tuple<double, double, double>;

auto make_change_vec(std::vector<std::vector<int>> const& classes) {
  std::vector<tii> res(std::size(classes));
  std::transform(std::begin(classes), std::end(classes), std::begin(res),
                 [](auto const& ele) {
                   return tii{change(ele[0], ele[1]), ele[0], ele[1]};
                 });
  return res;
}

class Solution {
 public:
  double maxAverageRatio(std::vector<std::vector<int>>& classes,
                         int extraStudents) {
    auto const change_vec = make_change_vec(classes);
    std::priority_queue<tii> pq{std::begin(change_vec), std::end(change_vec)};
    for (int i = 0; i < extraStudents; ++i) {
      auto [cur_change, num, denom] = pq.top();
      pq.pop();
      pq.push({change(num + 1, denom + 1), num + 1, denom + 1});
    }
    double sum = 0;
    auto const n = std::size(pq);
    while (not std::empty(pq)) {
      sum += std::get<1>(pq.top()) / std::get<2>(pq.top());
      pq.pop();
    }
    return sum / n;
  }
};
