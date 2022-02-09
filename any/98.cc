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

bool is_bst(TreeNode *root, long min, long max) {
  if (root == nullptr) return true;
  return (root->val > min) and (root->val < max)
         and is_bst(root->left, min, root->val)
         and is_bst(root->right, root->val, max);
}

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    return is_bst(
      root, numeric_limits<long>::min(), numeric_limits<long>::max());
  }
};
