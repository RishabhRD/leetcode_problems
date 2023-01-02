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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

using ll = long long;

void dfs(TreeNode *cur, TreeNode *parent,
         std::unordered_map<int, std::vector<int>> &graph) {
  graph[cur->val].push_back(parent->val);
  if (cur->left) {
    graph[cur->val].push_back(cur->left->val);
    dfs(cur->left, cur, graph);
  }
  if (cur->right) {
    graph[cur->val].push_back(cur->right->val);
    dfs(cur->right, cur, graph);
  }
}

class Solution {
 public:
  int amountOfTime(TreeNode *root, int start) {
    std::unordered_map<int, std::vector<int>> graph;
    dfs(root, root, graph);
    std::queue<int> q;
    std::unordered_set<int> visited;
    q.push(start);
    visited.insert(start);
    int cur_level = -1;
    while (!q.empty()) {
      auto sz = q.size();
      while (sz--) {
        auto top = q.front();
        q.pop();
        for (auto n : graph[top]) {
          if (visited.find(n) == visited.end()) {
            q.push(n);
            visited.insert(n);
          }
        }
      }
      ++cur_level;
    }
    return cur_level;
  }
};
