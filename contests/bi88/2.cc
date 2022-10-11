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

  int find(int i) {
    if (parent[i] == i)
      return i;
    else
      return parent[i] = find(parent[i]);
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

class LUPrefix {
  int max_ans = 0;
  std::vector<bool> exist;
  dsu dsu;

 public:
  LUPrefix(int n) : dsu(n + 1), exist(n + 2) {}

  void upload(int video) {
    exist[video] = true;
    if (exist[video - 1] == true) dsu.combine(video, video - 1);
    if (exist[video + 1] == true) dsu.combine(video, video + 1);
    if (dsu.size[dsu.find(1)] == 1) {
      if (exist[1]) max_ans = 1;
    } else {
      max_ans = dsu.size[dsu.find(1)];
    }
  }

  int longest() { return max_ans; }
};
