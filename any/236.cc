#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if(root == nullptr) return nullptr;
    if(root == p or root == q) return root;
    const auto left = lowestCommonAncestor(root->left, p, q);
    const auto right = lowestCommonAncestor(root->right, p, q);
    if(left and right) return root;
    return left == nullptr ? right : left;
  }
};
