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

class Solution {
 public:
  int largestComponentSize(std::vector<int>& nums) {
    auto const n = std::size(nums);
    dsu dsu((*std::max_element(std::begin(nums), std::end(nums))) + 1);
    for (auto const num : nums) {
      auto const max = std::sqrt(num);
      for (int i = 2; i <= max; ++i) {
        if (num % i == 0) {
          dsu.combine(num, i);
          dsu.combine(num, num / i);
        }
      }
    }
    std::unordered_map<int, int> mp;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      ans = std::max(ans, ++mp[dsu.find(nums[i])]);
    }
    return ans;
  }
};
