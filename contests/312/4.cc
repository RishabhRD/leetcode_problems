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

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void join(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;
    if (size[px] > size[py]) {
      parent[py] = px;
      size[px] += size[py];
    } else {
      parent[px] = py;
      size[py] += size[px];
    }
  }
};

class Solution {
 public:
  int numberOfGoodPaths(std::vector<int>& vals,
                        std::vector<std::vector<int>>& edges) {
    auto const n = std::size(vals);
    std::vector<std::vector<int>> graph(n);
    for (auto const& edge : edges) {
      if (vals[edge[0]] > vals[edge[1]]) {
        graph[edge[0]].push_back(edge[1]);
      } else {
        graph[edge[1]].push_back(edge[0]);
      }
    }

    std::map<int, std::vector<int>> node_map;
    for (int i = 0; i < n; ++i) {
      node_map[vals[i]].push_back(i);
    }

    dsu dsu(n);

    int res = 0;
    for (auto const& [val, val_nodes] : node_map) {
      for (auto node : val_nodes) {
        for (auto neighbor : graph[node]) {
          dsu.join(node, neighbor);
        }
      }
      std::unordered_map<int, int> freq_mp;
      for (auto node : val_nodes) {
        ++freq_mp[dsu.find(node)];
      }
      for (auto [k, v] : freq_mp) {
        res += ((v * (v - 1)) / 2);
      }
    }
    return res + n;
  }
};
