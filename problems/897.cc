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

struct ret_t {
  TreeNode *head;
  TreeNode *tail;
};

ret_t inorder(TreeNode *root) {
  if (root->left == nullptr and root->right == nullptr) return {root, root};
  TreeNode *head = root;
  TreeNode *tail = root;
  if (root->left) {
    auto [left_head, left_tail] = inorder(root->left);
    left_tail->right = root;
    root->left = nullptr;
    head = left_head;
  }
  if (root->right) {
    auto [right_head, right_tail] = inorder(root->right);
    root->right = right_head;
    tail = right_tail;
  }
  return {head, tail};
}

class Solution {
 public:
  TreeNode *increasingBST(TreeNode *root) { return inorder(root).head; }
};
