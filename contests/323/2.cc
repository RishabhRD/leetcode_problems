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

class Solution {
 public:
  int longestSquareStreak(std::vector<int>& nums) {
    ll const n = std::size(nums);
    std::unordered_map<int, int> idx_map;
    for (ll i = 0; i < std::size(nums); ++i) {
      idx_map[nums[i]] = i;
    }
    dsu dsu(n);
    for (ll ele : nums) {
      if (dsu.find(idx_map[ele]) == idx_map[ele]) {
        ll cur = ele;
        while (cur <= 1e5 && idx_map.find(cur) != idx_map.end()) {
          dsu.combine(idx_map[cur], idx_map[ele]);
          cur = cur * cur;
        }
      }
    }
    ll max = 1;
    for (ll i = 0; i < n; ++i) {
      max = std::max<ll>(max, dsu.size(i));
    }
    if (max == 1) return -1;
    return max;
  }
};
