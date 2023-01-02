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

using ll = long long;

class Solution {
 public:
  bool isPossible(int n, std::vector<std::vector<int>>& edges) {
    std::vector num_connections(n + 1, std::unordered_set<ll>());
    std::vector degree(n + 1, 0);
    for (auto const& e : edges) {
      auto const x = e[0];
      auto const y = e[1];
      num_connections[x].insert(y);
      num_connections[y].insert(x);
      ++degree[x];
      ++degree[y];
    }
    std::vector<ll> odds;
    for (ll i = 1; i <= n; ++i) {
      if (degree[i] % 2 == 1) odds.push_back(i);
    }
    if (odds.size() > 4 || odds.size() % 2 == 1) return false;
    if (odds.size() == 0) return true;
    if (odds.size() == 2) {
      auto const x = odds[0];
      auto const y = odds[1];
      auto const& nx = num_connections[x];
      auto const& ny = num_connections[y];
      if (nx.find(y) != nx.end()) {
        for (ll i = 1; i <= n; ++i) {
          if (i == x || i == y) continue;
          if (nx.find(i) == nx.end() && ny.find(i) == ny.end()) return true;
        }
        return false;
      }
      return true;
    }
    do {
      auto const x1 = odds[0];
      auto const y1 = odds[1];
      auto const x2 = odds[2];
      auto const y2 = odds[3];
      auto const& nx1 = num_connections[x1];
      auto const& nx2 = num_connections[x2];
      if (nx1.find(y1) != nx1.end() || nx2.find(y2) != nx2.end()) continue;
      return true;
    } while (std::next_permutation(std::begin(odds), std::end(odds)));
    return false;
  }
};
