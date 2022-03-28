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

struct ancestor_res_t {
  int max_value;
  int min_value;
  int largest_diff;
};

ancestor_res_t max_ancestor(TreeNode *root) {
  if (root == nullptr) { return { INT32_MIN, INT32_MAX, 0 }; }
  auto [left_max, left_min, left_diff] = max_ancestor(root->left);
  auto [right_max, right_min, right_diff] = max_ancestor(root->right);
  auto const max_val = max({ root->val, left_max, right_max });
  auto const min_val = min({ root->val, left_min, right_min });
  auto const diff_val = max({ abs(root->val - max_val),
    abs(root->val - min_val),
    left_diff,
    right_diff });
  return { max_val, min_val, diff_val };
}

class Solution {
public:
  int maxAncestorDiff(TreeNode *root) {
    return max_ancestor(root).largest_diff;
  }
};
