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

auto anc_diff(TreeNode* root, int mn, int mx) {
  if(root == nullptr) return mx - mn;
  mn = min(mn, root->val);
  mx = max(mx, root->val);
  return max(anc_diff(root->left, mn, mx), anc_diff(root->right, mn, mx));
}

class Solution {
public:
  int maxAncestorDiff(TreeNode *root) {
    return anc_diff(root, root->val, root->val);
  }
};
