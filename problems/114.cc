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


class Solution {
  TreeNode* prev{};
public:
  void flatten(TreeNode *root) {
    if(root == nullptr) return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = nullptr;
    prev = root;
  }
};
