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

class Solution {
 public:
  bool checkDistances(std::string s, std::vector<int>& distance) {
    auto const n = std::size(s);
    std::unordered_map<char, int> actual_dist(26);
    for (int i = 0; i < n; ++i) {
      auto const c = s[i];
      if (actual_dist.find(c) != actual_dist.end()) {
        auto old_dist = actual_dist[c];
        actual_dist[c] = i - old_dist - 1;
      } else {
        actual_dist[c] = i;
      }
    }
    for (char c = 'a'; c <= 'z'; ++c) {
      if (actual_dist.find(c) != actual_dist.end())
        if (distance[c - 'a'] != actual_dist[c]) return false;
    }
    return true;
  }
};
