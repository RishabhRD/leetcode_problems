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

using ll = long long;

class Solution {
 public:
  std::vector<bool> friendRequests(int n,
                                   std::vector<std::vector<int>>& restrictions,
                                   std::vector<std::vector<int>>& requests) {
    std::vector restriction_graph(n, std::unordered_set<int>());
    dsu dsu(n);
    std::vector<bool> res;
    auto can_connect = [&](auto u, auto v) {
      auto const pu = dsu.find(u);
      auto const pv = dsu.find(v);
      return std::all_of(
          std::begin(restrictions), std::end(restrictions),
          [&](auto const& restriction) {
            auto const x = restriction[0];
            auto const y = restriction[1];
            auto const px = dsu.find(x);
            auto const py = dsu.find(y);
            return !((px == pu and py == pv) || (px == pv and py == pu));
          });
    };
    for (auto const& req : requests) {
      auto const u = req[0];
      auto const v = req[1];
      if (can_connect(u, v)) {
        dsu.combine(u, v);
        res.push_back(true);
      } else {
        res.push_back(false);
      }
    }
    return res;
  }
};
