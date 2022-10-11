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

bool is_similar(std::string_view a, std::string_view b) {
  auto const n = std::size(a);
  int diff = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) ++diff;
  }
  return diff <= 2;
}

class Solution {
 public:
  int numSimilarGroups(std::vector<std::string>& strs) {
    auto const n = std::size(strs);
    dsu dsu(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (is_similar(strs[i], strs[j])) {
          dsu.combine(i, j);
        }
      }
    }
    std::unordered_set<int> st;
    for (int i = 0; i < n; ++i) st.insert(dsu.find(i));
    return st.size();
  }
};
