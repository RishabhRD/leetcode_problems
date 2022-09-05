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

std::tuple<int, int, int> dfs(TreeNode *root) {
  if (root == nullptr) return {-1, -1, -1};

  auto const [ll, lr, lm] = dfs(root->left);
  auto const [rl, rr, rm] = dfs(root->right);

  auto const max_of_both_subtrees = std::max(lm, rm);
  auto const max_of_a_path = std::max(lr, rl) + 1;
  auto const cur_subtree_max = std::max(max_of_a_path, max_of_both_subtrees);

  return {1 + lr, 1 + rl, cur_subtree_max};
}

class Solution {
 public:
  int longestZigZag(TreeNode *root) { return std::get<2>(dfs(root)); }
};
