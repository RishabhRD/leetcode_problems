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

int dfs(TreeNode* root){
  if(root == nullptr) return -1;
  if(root->left == nullptr) return -1;
  int left = root->left->val;
  int right = root->right->val;
  if(root->left->val == root->val){
    left = dfs(root->left);
  }
  if(root->right->val == root->val){
    right = dfs(root->right);
  }
  if(left != -1 and right != -1){
    return min(left, right);
  }else if(left != -1){
    return left;
  }else{
    return right;
  }
}

class Solution {
public:
  int findSecondMinimumValue(TreeNode *root) {
    return dfs(root);
  }
};
