#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void traverse(TreeNode *root, std::string &str) {
  if (root == nullptr) return;
  str += std::to_string(root->val);
  if (root->left) {
    str += '(';
    traverse(root->left, str);
    str += ')';
  }
  if (root->right) {
    if (!root->left) {
      str += "()";
    }
    str += '(';
    traverse(root->right, str);
    str += ')';
  }
}

class Solution {
 public:
  std::string tree2str(TreeNode *root) {
    std::string str;
    traverse(root, str);
    return str;
  }
};
