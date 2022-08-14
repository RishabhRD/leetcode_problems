#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

auto safe_left(TreeNode *root) -> TreeNode * {
  if (root == nullptr) {
    return nullptr;
  }
  return root->left;
}

auto safe_right(TreeNode *root) -> TreeNode * {
  if (root == nullptr) {
    return nullptr;
  }
  return root->right;
}

auto children(TreeNode *root) -> std::array<TreeNode *, 2> {
  return {safe_left(root), safe_right(root)};
}

auto grandchildren(TreeNode *root) -> std::array<TreeNode *, 4> {
  return {safe_left(safe_left(root)), safe_left(safe_right(root)),
          safe_right(safe_left(root)), safe_right(safe_right(root))};
}

class Solution {
  std::unordered_map<TreeNode *, int> mp;

 public:
  int rob(TreeNode *root) {
    if (root == nullptr) return 0;
    if (mp[root]) return mp[root];

    auto with_robbing_here = root->val;
    for (auto nodes : grandchildren(root)) {
      with_robbing_here += rob(nodes);
    }

    auto without_robbing_here = 0;
    for (auto nodes : children(root)) {
      without_robbing_here += rob(nodes);
    }

    mp[root] = max(with_robbing_here, without_robbing_here);

    return mp[root];
  }
};
