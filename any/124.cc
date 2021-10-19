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

int max_path_sum(TreeNode* root, int& max_val){
  if(root == nullptr) return 0;
  const int left_gain = max(0, max_path_sum(root->left, max_val));
  const int right_gain = max(0, max_path_sum(root->right, max_val));
  max_val = max(max_val, left_gain + right_gain + root->val);
  return root->val + max(left_gain, right_gain);
}

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    int max_val = -1e8;
    max_path_sum(root, max_val);
    return max_val;
  }
};
