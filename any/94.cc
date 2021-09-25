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

template<typename Func> void traverse(TreeNode *root, Func &&func) {
  if (root == nullptr) return;
  traverse(root->left, func);
  func(root);
  traverse(root->right, func);
}

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> vec;
    traverse(root, [&](auto x) { vec.push_back(x->val); });
    return vec;
  }
};
