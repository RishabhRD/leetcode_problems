#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};

auto get(unordered_map<int, TreeNode *> &mp, int node_val) {
  if (mp.find(node_val) != mp.end()) {
    return mp.at(node_val);
  } else {
    TreeNode *new_node = new TreeNode(node_val);
    mp[node_val] = new_node;
    return new_node;
  }
}

class Solution {
public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> node_map;
    unordered_map<int, int> parent_map;
    for (auto const &desc : descriptions) {
      auto parent = get(node_map, desc[0]);
      auto child = get(node_map, desc[1]);
      if (desc[2]) {
        parent->left = child;
      } else {
        parent->right = child;
      }
      parent_map[child->val] = parent->val;
    }
    for (auto [k, v] : node_map) {
      if (parent_map.find(k) == parent_map.end()) { return v; }
    }
    return nullptr;
  }
};
