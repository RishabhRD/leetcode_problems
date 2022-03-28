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

struct Solution {
  vector<pair<TreeNode *, TreeNode *>> vec;
  TreeNode *prev = NULL;
  void inorder(TreeNode *root) {
    if (!root) return;
    inorder(root->left);
    if (prev && prev->val > root->val) vec.push_back({ prev, root });
    prev = root;
    inorder(root->right);
  }
  void recoverTree(TreeNode *root) {
    inorder(root);
    if (vec.size() == 1) swap(vec[0].first->val, vec[0].second->val);
    if (vec.size() == 2) swap(vec[0].first->val, vec[1].second->val);
  }
};
