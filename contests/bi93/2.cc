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

using graph_t = std::vector<std::vector<ll>>;

auto build_graph(ll n, std::vector<std::vector<int>> const& edges,
                 std::vector<int> const& vals) {
  graph_t graph(n);
  for (auto const& edge : edges) {
    auto const x = edge[0];
    auto const y = edge[1];
    if (vals[y] > 0) graph[x].push_back(vals[y]);
    if (vals[x] > 0) graph[y].push_back(vals[x]);
  }
  return graph;
}

class Solution {
 public:
  int maxStarSum(std::vector<int>& vals, std::vector<std::vector<int>>& edges,
                 int k) {
    auto const n = std::size(vals);
    auto graph = build_graph(n, edges, vals);
    ll ans = INT32_MIN;
    for (ll i = 0; i < n; ++i) {
      std::sort(std::begin(graph[i]), std::end(graph[i]), std::greater<>{});
      ll cur_ans = vals[i];
      for (ll j = 0; j < std::min<ll>(k, std::size(graph[i])); ++j) {
        cur_ans += graph[i][j];
      }
      ans = std::max(ans, cur_ans);
    }
    return ans;
  }
};
