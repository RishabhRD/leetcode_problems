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

auto path_sum(TreeNode *root) -> pair<int, int> {
  if (root == nullptr) return { INT32_MIN, 0 };
  auto const [left_max_path, left_single_path] = path_sum(root->left);
  auto const [right_max_path, right_single_path] = path_sum(root->right);
  auto const single_path = max({
    root->val,
    root->val + left_single_path,
    root->val + right_single_path,
  });
  auto const max_path = max({
    root->val,
    left_max_path,
    right_max_path,
    root->val + left_single_path,
    root->val + right_single_path,
    root->val + right_single_path + left_single_path,
  });
  return { max_path, single_path };
}

class Solution {
public:
  int maxPathSum(TreeNode *root) { return path_sum(root).first; }
};
