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
    if (parent[x] == x)
      return x;
    else
      return parent[x] = find(parent[x]);
  }

  void combine(int x, int y) {
    auto const p_x = find(x);
    auto const p_y = find(y);
    if (p_x == p_y) return;
    if (size[p_x] > size[p_y]) {
      size[p_x] += size[p_y];
      parent[p_y] = p_x;
    } else {
      size[p_y] += size[p_x];
      parent[p_x] = p_y;
    }
  }
};

std::string to_string(std::vector<int> const& vec, std::string_view str) {
  std::string os;
  for (auto ele : vec) os.push_back(str[ele]);
  return os;
}

std::string sort(std::string str) {
  int idx = 0;
  std::array<int, 26> freq{0};
  for (auto c : str) ++freq[c - 'a'];
  for (int i = 0; i < 26; ++i) {
    while (freq[i]--) {
      str[idx++] = i + 'a';
    }
  }
  return str;
}

class Solution {
 public:
  std::string smallestStringWithSwaps(std::string s,
                                      std::vector<std::vector<int>>& pairs) {
    auto const n = std::size(s);
    dsu dsu(n);
    for (auto const& pair : pairs) dsu.combine(pair[0], pair[1]);
    std::unordered_map<int, std::vector<int>> groups;
    for (int i = 0; i < n; ++i) {
      groups[dsu.find(i)].push_back(i);
    }
    for (auto const& [k, vec] : groups) {
      auto const str = sort(to_string(vec, s));
      for (int i = 0; i < std::size(vec); ++i) {
        s[vec[i]] = str[i];
      }
    }
    return s;
  }
};
