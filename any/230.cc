#include <utility>
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

template<typename Func> void inorder_traversal(TreeNode *root, Func &&func) {
  if (root == nullptr) return;
  inorder_traversal(root->left, func);
  func(root->val);
  inorder_traversal(root->right, func);
}

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    auto ele{ 0 };
    auto func = [&](int val) {
      k--;
      if (k == 0) ele = val;
    };
    inorder_traversal(root, func);
    return ele;
  }
};
