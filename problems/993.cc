#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <optional>
#include <queue>
#include <vector>

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

bool is_ele(TreeNode *root, int ele) {
  return root != nullptr and root->val == ele;
}

std::optional<std::pair<int, TreeNode *>> find_depth_and_parent(TreeNode *root,
                                                                int ele) {
  if (root == nullptr) return {};
  auto left = find_depth_and_parent(root->left, ele);
  auto right = find_depth_and_parent(root->right, ele);
  if (left.has_value()) {
    ++left->first;
    return left;
  } else if (right.has_value()) {
    ++right->first;
    return right;
  }
  if (is_ele(root->left, ele) || is_ele(root->right, ele)) {
    return std::pair{1, root};
  }
  return {};
}

class Solution {
 public:
  bool isCousins(TreeNode *root, int x, int y) {
    auto x_val = find_depth_and_parent(root, x);
    auto y_val = find_depth_and_parent(root, y);
    if (x_val and y_val) {
      return x_val->first == y_val->first and x_val->second != y_val->second;
    }
    return false;
  }
};
