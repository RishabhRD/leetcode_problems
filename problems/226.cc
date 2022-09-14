#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

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

std::vector<int> reverse_level_order(TreeNode *root) {
  if (root == nullptr) return {};
  std::vector<int> vector;
  std::queue<TreeNode *> q;
  while (not q.empty()) {
    auto const front = q.front();
    q.pop();
    vector.push_back(front->val);
    if (front->right != nullptr) q.push(front->right);
    if (front->left != nullptr) q.push(front->left);
  }
  return vector;
}

class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) return nullptr;
    auto left = invertTree(root->left);
    auto right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};
