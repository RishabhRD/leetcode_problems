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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};

bool is_symmetric(TreeNode *r1, TreeNode *r2) {
  if (r1 == nullptr and r2 == nullptr) {
    return true;
  } else if (r1 and r2) {
    if (r1->val != r2->val) return false;
    return is_symmetric(r1->left, r2->right)
           and is_symmetric(r1->right, r2->left);
  } else {
    return false;
  }
}

class Solution {
public:
  bool isSymmetric(TreeNode *root) { return is_symmetric(root, root); }
};
