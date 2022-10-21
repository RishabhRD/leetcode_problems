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

class Solution {
 public:
  int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
    dsu dsu(n + 1);
    int ans = 0;
    for (auto const& edge : edges) {
      if (edge[0] == 3) {
        auto const x = edge[1];
        auto const y = edge[2];
        if (dsu.find(x) == dsu.find(y)) {
          ++ans;
        } else {
          dsu.combine(x, y);
        }
      }
    }

    auto alice_dsu = dsu;
    for (auto const& edge : edges) {
      if (edge[0] == 1) {
        auto const x = edge[1];
        auto const y = edge[2];
        if (alice_dsu.find(x) == alice_dsu.find(y)) {
          ++ans;
        } else {
          alice_dsu.combine(x, y);
        }
      }
    }

    auto bob_dsu = dsu;
    for (auto const& edge : edges) {
      if (edge[0] == 2) {
        auto const x = edge[1];
        auto const y = edge[2];
        if (bob_dsu.find(x) == bob_dsu.find(y)) {
          ++ans;
        } else {
          bob_dsu.combine(x, y);
        }
      }
    }

    std::unordered_set<int> alice_set;
    for (int i = 1; i <= n; ++i) alice_set.insert(alice_dsu.find(i));

    std::unordered_set<int> bob_set;
    for (int i = 1; i <= n; ++i) bob_set.insert(bob_dsu.find(i));
    if (alice_set.size() != 1 || bob_set.size() != 1) return -1;
    return ans;
  }
};
