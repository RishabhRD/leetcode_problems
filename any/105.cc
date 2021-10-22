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

TreeNode* get_root(vector<int>& preorder, vector<int>& inorder, int low, int high, int& cur_idx){
  if(low > high) return nullptr;
  int cur_ele = preorder[cur_idx];
  TreeNode* root = new TreeNode(cur_ele);
  int i = low;
  for(; i <= high; i++){
    if(inorder[i] == cur_ele) break;
  }
  cur_idx++;
  root->left = get_root(preorder, inorder, low, i - 1, cur_idx);
  root->right = get_root(preorder, inorder, i + 1, high, cur_idx);
  return root;
}

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int cur_idx = 0;
    return get_root(preorder, inorder, 0, size(preorder) - 1, cur_idx);
  }
};
