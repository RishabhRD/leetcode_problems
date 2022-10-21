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
  int edgeScore(std::vector<int>& edges) {
    ll const n = std::size(edges);
    std::vector edge_score(n, 0ll);
    for (ll i = 0; i < n; ++i) {
      edge_score[edges[i]] += i;
    }
    return std::distance(
        std::begin(edge_score),
        std::max_element(std::begin(edge_score), std::end(edge_score)));
  }
};
