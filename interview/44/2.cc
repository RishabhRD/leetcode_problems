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

pair<TreeNode *, int> lca_deepest(TreeNode *root) {
  if (root == nullptr) return { root, 0 };
  auto [left_root, h_left] = lca_deepest(root->left);
  auto [right_root, h_right] = lca_deepest(root->right);
  if (h_left == h_right)
    return { root, h_left + 1 };
  else if (h_left > h_right)
    return { left_root, h_left + 1 };
  else
    return { right_root, h_right + 1 };
}

class Solution {
public:
  TreeNode *lcaDeepestLeaves(TreeNode *root) { return lca_deepest(root).first; }
};
