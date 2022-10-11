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
 public:
  std::vector<int> parent;
  std::vector<int> size;
  dsu(int n) : parent(n), size(n, 1) {
    std::iota(std::begin(parent), std::end(parent), 0);
  }

  int find(int n) {
    if (parent[n] == n) return n;
    return parent[n] = find(parent[n]);
  }

  void combine(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;
    if (size[px] >= size[py]) {
      size[px] += size[py];
      parent[py] = px;
    } else {
      size[py] += size[px];
      parent[px] = py;
    }
  }
};

auto diff(std::vector<int> const& src, std::vector<int> const& dist,
          std::vector<int> const& idx) {
  std::unordered_map<int, int> mp;
  for (int i : idx) ++mp[dist[i]];
  for (int i : idx) --mp[src[i]];
  int ans = 0;
  for (auto [k, v] : mp) {
    if (v >= 0) ans += v;
  }
  return ans;
}

class Solution {
 public:
  int minimumHammingDistance(std::vector<int>& source, std::vector<int>& target,
                             std::vector<std::vector<int>>& allowedSwaps) {
    auto const n = std::size(source);
    dsu dsu(n);
    for (auto const& edge : allowedSwaps) {
      dsu.combine(edge[0], edge[1]);
    }

    std::unordered_map<int, std::vector<int>> mp;
    for (int i = 0; i < n; ++i) {
      mp[dsu.find(i)].push_back(i);
    }

    int ans = 0;
    for (auto const& [k, v] : mp) {
      ans += diff(source, target, v);
    }
    return ans;
  }
};
