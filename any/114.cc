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

void flatten_tree(TreeNode *root, TreeNode*& prev) {
  if(root == nullptr) return;
  flatten_tree(root->right, prev);
  flatten_tree(root->left, prev);
  root->right = prev;
  root->left = nullptr;
  prev = root;
}

class Solution {
public:
  void flatten(TreeNode *root) {
    TreeNode* prev = nullptr;
    flatten_tree(root, prev);
  }
};
