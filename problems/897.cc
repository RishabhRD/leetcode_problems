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

template<typename Func> void traverse(TreeNode *root, Func &&func) {
  if (root == nullptr) return;
  traverse(root->left, func);
  func(root);
  traverse(root->right, func);
}

class Solution {
public:
  TreeNode *increasingBST(TreeNode *root, TreeNode* tail = nullptr) {
    if(not root) return tail;
    auto res = increasingBST(root->left, root);
    root->left = nullptr;
    root->right = increasingBST(root->right, tail);
    return res;
  }
};

int main(){
  TreeNode n2 (2);
  TreeNode n1 (1);
  TreeNode n4 (4);
  TreeNode n3 (3);
  n2.left = &n1;
  n1.left = &n4;
  n1.right = &n3;
  Solution sol;
  sol.increasingBST(&n2);
}
