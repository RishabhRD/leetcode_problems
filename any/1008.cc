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

TreeNode* traverse(const vector<int>& preorder, int& index, int bound = INT32_MAX){
  if(index >= size(preorder) or preorder[index] > bound) return nullptr;
  auto node = new TreeNode(preorder[index++]);
  node->left = traverse(preorder, index, node->val);
  node->right = traverse(preorder, index, bound);
  return node;
}

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int index = 0;
      return traverse(preorder, index);
    }
};
