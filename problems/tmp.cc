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

class dsu {
 private:
  using ll = long long;
  std::vector<ll> parent_;
  std::vector<ll> size_;

 public:
  dsu(ll n) {
    for (int i = 0; i < n; ++i) parent_.push_back(i);
    for (int i = 0; i < n; ++i) {
      size_.push_back(1);
    }
  }

  // average case: O(1)
  ll find(ll n) {
    if (parent_[n] == n) return n;
    return parent_[n] = find(parent_[n]);
  }

  // average case: O(1)
  void combine(ll x, ll y) {
    auto const px = find(x);
    auto const py = find(y);
    if (size_[px] > size_[py]) {
      parent_[py] = px;
      size_[px] += size_[py];
    } else {
      parent_[px] = py;
      size_[py] += size_[px];
    }
  }

  // average case: O(1)
  ll size(int n) { return size_[find(n)]; }
};
