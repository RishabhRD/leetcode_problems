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

class Solution {
 public:
  std::vector<bool> areConnected(int n, int threshold,
                                 std::vector<std::vector<int>>& queries) {
    dsu dsu(n + 1);
    for (int i = threshold + 1; i <= n; ++i) {
      for (int m = 1; i * m <= n; ++m) {
        dsu.combine(i, i * m);
      }
    }
    std::vector<bool> res;
    for (auto const& query : queries) {
      res.push_back(dsu.find(query[0]) == dsu.find(query[1]));
    }
    return res;
  }
};
