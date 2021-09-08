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

template<typename Func>
void inorder_traversal(TreeNode *root, const Func &func) {
  if (root == nullptr) return;
  inorder_traversal(root->left, func);
  func(root);
  inorder_traversal(root->right, func);
}

TreeNode* make_balance_tree(int low, int high, const vector<int>& vec){
  if(low > high) return nullptr;
  int mid = (low + high) / 2;
  TreeNode* root = new TreeNode(vec[mid]);
  root->left = make_balance_tree(low, mid - 1, vec);
  root->right = make_balance_tree(mid + 1, high, vec);
  return root;
}

class Solution {
public:
  TreeNode *balanceBST(TreeNode *root) {
    vector<int> values;
    inorder_traversal(
      root, [&](TreeNode *root) { values.push_back(root->val); });
    return make_balance_tree(0, size(values) - 1, values);
  }
};
