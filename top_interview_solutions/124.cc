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

using ll = long long;

std::pair<ll, ll> max_path(TreeNode *root) {
  if (root == nullptr) {
    return {0, INT32_MIN};
  }

  auto const [left_single_path_max, left_subtree_max] = max_path(root->left);
  auto const [right_single_path_max, right_subtree_max] = max_path(root->right);

  auto const single_path_max = std::max<ll>(
      root->val + std::max(left_single_path_max, right_single_path_max),
      root->val);
  auto const subtree_max = std::max<ll>({
      left_subtree_max,
      right_subtree_max,
      single_path_max,
      root->val + left_single_path_max + right_single_path_max,
      root->val,
  });

  return {single_path_max, subtree_max};
}

class Solution {
 public:
  int maxPathSum(TreeNode *root) { return std::get<1>(max_path(root)); }
};
