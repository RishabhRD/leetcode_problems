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

using graph_t =
    std::unordered_map<std::string_view, std::vector<std::string_view>>;

class Solution {
 public:
  std::vector<std::string> findAllRecipes(
      std::vector<std::string>& recipes,
      std::vector<std::vector<std::string>>& ingredients,
      std::vector<std::string>& supplies) {
    graph_t graph;
    auto const n = std::size(recipes);
    std::unordered_map<std::string_view, int> indegree;
    for (int i = 0; i < n; ++i) {
      std::string_view v = recipes[i];
      for (std::string_view u : ingredients[i]) {
        graph[u].push_back(v);
        ++indegree[v];
      }
    }
    std::queue<std::string_view> q;
    for (std::string_view u : supplies) {
      if (indegree[u] == 0) q.push(u);
    }
    std::unordered_set<std::string_view> supplies_set{std::begin(supplies),
                                                      std::end(supplies)};
    while (not q.empty()) {
      auto u = q.front();
      q.pop();
      for (auto v : graph[u]) {
        --indegree[v];
        if (indegree[v] == 0) {
          q.push(v);
        }
      }
    }
    std::vector<std::string> ans;
    for (std::string_view r : recipes) {
      if (indegree[r] == 0) ans.push_back(std::string(r));
    }
    return ans;
  }
};
