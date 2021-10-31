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

int ps(TreeNode* root, int& res){
  if(not root) return 0;
  int lp = ps(root->left, res);
  int rp = ps(root->right, res);
  res = max(res, root->val + (lp >= 0 ? lp : 0) + (rp >= 0 ? rp : 0));
  return max({lp + root->val, rp + root->val, root->val});
}

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    int res = INT32_MIN;
    ps(root, res);
    return res;
  }
};
