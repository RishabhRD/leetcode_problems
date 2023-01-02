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

std::pair<ll, ll> find_height(ll i, ll parent,
                              std::vector<std::vector<ll>> const& graph) {
  ll height = 1;
  ll node = i;
  for (auto n : graph[i]) {
    if (n != parent) {
      auto const [nh, nd] = find_height(n, i, graph);
      if (nh + 1 > height) {
        node = nd;
        height = nh + 1;
      }
    }
  }
  return {height, node};
}

std::pair<ll, ll> find_diameter(std::vector<std::vector<ll>> const& graph) {
  auto [_, n1] = find_height(0, 0, graph);
  auto [__, n2] = find_height(n1, n1, graph);
  return {n1, n2};
}

void dfs(ll i, ll parent, ll target, std::vector<ll>& cur, std::vector<ll>& res,
         std::vector<std::vector<ll>> const& graph) {
  cur.push_back(i);
  if (i == target) res = cur;
  for (auto n : graph[i]) {
    if (n != parent) {
      dfs(n, i, target, cur, res, graph);
    }
  }
  cur.pop_back();
}

class Solution {
 public:
  std::vector<int> findMinHeightTrees(int n,
                                      std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<ll>> graph(n);
    for (auto const& edge : edges) {
      auto const x = edge[0];
      auto const y = edge[1];
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    auto [n1, n2] = find_diameter(graph);
    std::vector<ll> cur;
    std::vector<ll> res;
    dfs(n1, n1, n2, cur, res, graph);
    auto const m = res.size();
    if (m % 2 == 1) {
      return std::vector<int>({int(res[m / 2])});
    } else {
      return std::vector<int>({int(res[m / 2]), int(res[(m - 1) / 2])});
    }
  }
};
