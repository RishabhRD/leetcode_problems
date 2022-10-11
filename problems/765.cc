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

int couple(int ele) { return ele / 2; }

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
  int minSwapsCouples(std::vector<int>& row) {
    auto const n = std::size(row);
    dsu dsu(n / 2);
    for (int i = 0; i < n; i += 2) {
      dsu.combine(couple(row[i]), couple(row[i + 1]));
    }
    std::unordered_set<int> mp;
    for (int i = 0; i < n / 2; ++i) {
      mp.insert(dsu.find(i));
    }
    return (n / 2) - mp.size();
  }
};
