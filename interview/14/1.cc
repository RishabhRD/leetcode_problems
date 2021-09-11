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

bool is_mirror(TreeNode* first, TreeNode* second){
  if(first and second){
    if(first->val != second->val) return false;
    else{
      return is_mirror(first->left, second->right) and is_mirror(first->right, second->left);
    }
  }else if(first or second){
    return false;
  }else{
    return true;
  }
}

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    return is_mirror(root, root);
  }
};
