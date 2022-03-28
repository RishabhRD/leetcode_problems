#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

TreeNode *find_min(TreeNode *root) {
  while (root->left) { root = root->left; }
  return root;
}

class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return nullptr;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else {
      if (root->left == nullptr)
        return root->right;
      else if (root->right == nullptr)
        return root->left;
      else {
        auto min_node = find_min(root->right);
        root->val = min_node->val;
        root->right = deleteNode(root->right, min_node->val);
      }
    }
    return root;
  }
};
