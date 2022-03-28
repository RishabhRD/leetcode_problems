#include <queue>
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
public:
  bool isCousins(TreeNode *root, int x, int y) {
    if (root->val == x or root->val == y) return false;
    queue<TreeNode *> q;
    q.push(root);
    int level_x = -1;
    int level_y = -1;
    TreeNode *parent_x{};
    TreeNode *parent_y{};
    int cur_level = -1;
    while (not empty(q)) {
      int sz = size(q);
      cur_level++;
      while (sz--) {
        auto parent = q.front();
        if (parent->val == x) level_x = cur_level;
        if (parent->val == y) level_y = cur_level;
        q.pop();
        auto left = parent->left;
        auto right = parent->right;
        if (left) {
          if (left->val == x) parent_x = parent;
          if (left->val == y) parent_y = parent;
          q.push(left);
        }
        if (right) {
          if (right->val == x) parent_x = parent;
          if (right->val == y) parent_y = parent;
          q.push(right);
        }
      }
    }
    if (level_x != level_y) return false;
    return parent_x != parent_y;
  }
};
