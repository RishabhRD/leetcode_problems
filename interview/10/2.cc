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


TreeNode *del_node(TreeNode *root, int key) {
  if (not root) return root;
  if (key > root->val) {
    root->right = del_node(root->right, key);
  } else if (key < root->val) {
    root->left = del_node(root->left, key);
  } else {
    if ((not root->left) and (not root->right)) return nullptr;
    if ((not root->left) or (not root->right))
      return root->left ? root->left : root->right;
    auto right_subtree = root->right;
    while (right_subtree->left) { right_subtree = right_subtree->left; }
    root->val = right_subtree->val;
    root->right = del_node(root->right, root->val);
  }
  return root;
}

class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) { return del_node(root, key); }
};
