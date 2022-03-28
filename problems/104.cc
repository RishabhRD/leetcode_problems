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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int max_depth(TreeNode* root){
  if(root == nullptr) return 0;
  return 1 + max(max_depth(root->left), max_depth(root->right));
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
      return max_depth(root);
    }
};
