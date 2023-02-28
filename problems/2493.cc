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

class dsu {
 private:
  using ll = long long;
  std::vector<ll> parent_;
  std::vector<ll> size_;

 public:
  dsu(ll n) : parent_(n), size_(n, 1) {
    std::iota(std::begin(parent_), std::end(parent_), 0);
  }

  ll find(ll n) {
    if (parent_[n] == n) return n;
    return parent_[n] = find(parent_[n]);
  }

  void combine(ll x, ll y) {
    auto const px = find(x);
    auto const py = find(y);
    if (px == py) return;
    if (size_[px] >= size_[py]) {
      size_[px] += size_[py];
      parent_[py] = px;
    } else {
      size_[py] += size_[px];
      parent_[px] = py;
    }
  }

  auto size(ll n) { return size_[find(n)]; }
};

bool has_odd_cycle(ll i, std::vector<std::vector<ll>> const& graph,
                   std::vector<bool>& visited, std::vector<ll>& visiting,
                   ll level) {
  if (visiting[i] != -1 && (level - visiting[i]) % 2 == 1) {
    // std::cout << i << ' ' << level << ' ' << visiting[i] << std::endl;
    return true;
  }
  if (visited[i]) return false;
  visited[i] = true;
  visiting[i] = level;
  for (auto n : graph[i]) {
    if (has_odd_cycle(n, graph, visited, visiting, level + 1)) return true;
  }
  visiting[i] = -1;
  return false;
}

ll max_dist(ll i, std::vector<std::vector<ll>> const& graph, ll n) {
  ll max_dist = 0;
  std::vector<bool> visited(n + 1);
  std::queue<ll> q;
  ll cur_level = 1;
  q.push(i);
  visited[i] = true;
  while (!q.empty()) {
    auto sz = q.size();
    while (sz--) {
      auto const top = q.front();
      q.pop();
      max_dist = std::max(max_dist, cur_level);
      for (auto n : graph[top]) {
        if (!visited[n]) {
          visited[n] = true;
          q.push(n);
        }
      }
    }
    ++cur_level;
  }
  return max_dist;
}

class Solution {
 public:
  int magnificentSets(int n, std::vector<std::vector<int>>& edges) {
    std::vector graph(n + 1, std::vector<ll>());
    dsu dsu(n + 1);
    for (auto const& edge : edges) {
      auto const x = edge[0];
      auto const y = edge[1];
      dsu.combine(x, y);
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    std::vector<bool> visited(n + 1);
    std::vector<ll> visiting(n + 1, -1);
    for (ll i = 1; i <= n; ++i) {
      if (!visited[i]) {
        if (has_odd_cycle(i, graph, visited, visiting, 0)) {
          return -1;
        }
      }
    }
    std::vector<ll> group_size(n + 1);
    for (ll i = 1; i <= n; ++i) {
      auto const parent = dsu.find(i);
      group_size[parent] = std::max(group_size[parent], max_dist(i, graph, n));
    }
    return std::reduce(std::begin(group_size), std::end(group_size), 0);
  }
};
