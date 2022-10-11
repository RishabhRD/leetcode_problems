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

std::pair<bool, int> is_balanced(TreeNode *root) {
  if (root == nullptr) return {true, 0};
  auto const [left_balanced, left_height] = is_balanced(root->left);
  auto const [right_balanced, right_height] = is_balanced(root->right);
  if (left_balanced and right_balanced and
      std::abs(left_height - right_height) <= 1) {
    return {true, 1 + std::max(left_height, right_height)};
  } else {
    return {false, -1};
  }
}

class Solution {
 public:
  bool isBalanced(TreeNode *root) { return is_balanced(root).first; }
};
