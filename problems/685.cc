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

auto findDuplicateParentEdge(std::vector<std::vector<int>> const& edges) {
  auto const n = std::size(edges);
  std::vector parent(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    auto const u = edges[i][0];
    auto const v = edges[i][1];
    if (parent[v] != 0) {
      return std::pair{parent, i};
    } else {
      parent[v] = u;
    }
  }
  return std::pair{parent, -1};
}

auto findCycleCausingEdge(std::vector<std::vector<int>> const& edges,
                          int edgeRemoved) {
  auto const n = std::size(edges);
  dsu dsu(n + 1);
  for (int i = 0; i < n; ++i) {
    if (i == edgeRemoved) continue;
    auto const u = edges[i][0];
    auto const v = edges[i][1];
    if (dsu.find(u) == dsu.find(v)) {
      return i;
    }
    dsu.combine(u, v);
  }
  return -1;
}

class Solution {
 public:
  std::vector<int> findRedundantDirectedConnection(
      std::vector<std::vector<int>> const& edges) {
    auto const [parent, edgeRemoved] = findDuplicateParentEdge(edges);
    auto const cycleCausingEdge = findCycleCausingEdge(edges, edgeRemoved);
    if (edgeRemoved == -1) return edges[cycleCausingEdge];
    if (cycleCausingEdge == -1) return edges[edgeRemoved];
    return {parent[edges[edgeRemoved][1]], edges[edgeRemoved][1]};
  }
};
