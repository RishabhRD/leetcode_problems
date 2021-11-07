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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
  if(root == nullptr or root == p or root == q) return root;
  auto left = lca(root->left, p, q);
  auto right = lca(root->right, p, q);
  if(left and right) return root;
  else if(left) return left;
  else return right;
}

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return lca(root, p, q);
  }
};
