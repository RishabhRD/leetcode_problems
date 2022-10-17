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

bool bfs(int const target, std::vector<std::vector<int>> const& graph,
         std::vector<int> degree, std::vector<int> q, std::vector<int> nums) {
  while (not std::empty(q)) {
    std::vector<int> q1;
    for (auto const i : q) {
      degree[i] = 0;
      if (nums[i] > target) return false;
      for (auto const n : graph[i]) {
        --degree[n];
        if (degree[n] >= 0) {
          if (nums[i] < target) {
            nums[n] += nums[i];
          }
          if (degree[n] == 1) {
            q1.push_back(n);
          } else if (degree[n] == 0) {
            return nums[n] == target;
          }
        }
      }
    }
    q = std::move(q1);
  }
  return true;
}

class Solution {
 public:
  int componentValue(std::vector<int> const& nums,
                     std::vector<std::vector<int>>& edges) {
    auto const n = std::size(nums);
    std::vector<std::vector<int>> graph(n);
    std::vector degree(n, 0);
    for (auto const& edge : edges) {
      auto const x = edge[0];
      auto const y = edge[1];
      graph[x].push_back(y);
      graph[y].push_back(x);
      ++degree[x];
      ++degree[y];
    }

    std::vector<int> q;
    for (int i = 0; i < n; ++i)
      if (degree[i] == 1) q.push_back(i);
    if (q.empty()) return 0;
    auto const sum = std::reduce(std::cbegin(nums), std::cend(nums), 0);
    for (int i = 1; i <= sum; ++i) {
      if (sum % i == 0 and bfs(i, graph, degree, q, nums)) {
        return (sum / i) - 1;
      }
    }
    return 0;
  }
};
