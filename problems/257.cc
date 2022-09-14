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

auto is_leaf(TreeNode *root) {
  return root->left == nullptr and root->right == nullptr;
}

auto add(std::string &cur, int val) { cur += "->" + std::to_string(val); }

// precondition: cur should end with ->num
// postcondition: last ->num of cur should be removed
auto remove_last(std::string &cur) {
  auto dash_loc = std::find(std::rbegin(cur), std::rend(cur), '>').base() - 2;
  cur.erase(dash_loc, std::end(cur));
}

// root is never null
void make_strings(TreeNode *root, std::string &cur,
                  std::vector<std::string> &vec) {
  add(cur, root->val);
  if (is_leaf(root)) {
    vec.push_back(cur);
  } else {
    if (root->left) make_strings(root->left, cur, vec);
    if (root->right) make_strings(root->right, cur, vec);
  }
  remove_last(cur);
}

class Solution {
 public:
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    if (root == nullptr) return {};
    std::string cur = std::to_string(root->val);
    std::vector<std::string> vec;
    if (is_leaf(root)) {
      vec.push_back(cur);
    } else {
      if (root->left) make_strings(root->left, cur, vec);
      if (root->right) make_strings(root->right, cur, vec);
    }
    return vec;
  }
};
