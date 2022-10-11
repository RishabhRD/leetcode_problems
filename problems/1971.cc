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
  std::vector<int> parent;
  std::vector<int> size;

 public:
  dsu(int n) : parent(n), size(n, 1) {
    std::iota(std::begin(parent), std::end(parent), 0);
  }

  int find(int n) {
    if (parent[n] == n) {
      return n;
    } else {
      return parent[n] = find(parent[n]);
    }
  }

  void combine(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;

    if (size[px] > size[py]) {
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
  bool validPath(int n, std::vector<std::vector<int>>& edges, int source,
                 int destination) {
    dsu dsu(n);
    for (auto const& e : edges) dsu.combine(e[0], e[1]);
    return dsu.find(source) == dsu.find(destination);
  }
};
