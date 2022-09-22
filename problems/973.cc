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

int dist(int a, int b) { return a * a + b * b; }

class Solution {
 public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points,
                                         int k) {
    auto cmp = [](auto const& a, auto const& b) {
      return dist(a[0], a[1]) > dist(b[0], b[1]);
    };

    using vii = std::vector<int>;
    std::priority_queue<vii, std::vector<vii>, decltype(cmp)> pq(
        std::begin(points), std::end(points), cmp);
    std::vector<std::vector<int>> res;
    for (int i = 0; i < k and not std::empty(pq); ++i) {
      res.push_back(pq.top());
      pq.pop();
    }
    return res;
  }
};
