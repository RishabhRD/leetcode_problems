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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* prune_tree(TreeNode* root){
  if(root == nullptr) return root;
  bool has_1 = false;
  if(root->val == 1) has_1 = true;
  root->left = prune_tree(root->left);
  if(root->left) has_1 = true;
  root->right = prune_tree(root->right);
  if(root->right) has_1 = true;
  if(has_1) return root;
  else return nullptr;
}

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
      return prune_tree(root);
    }
};
