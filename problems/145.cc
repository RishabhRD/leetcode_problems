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

template <typename Func>
auto postorder(TreeNode *root, Func processor) {
  if (root == nullptr) return;
  postorder(root->left, processor);
  postorder(root->right, processor);
  processor(root);
}

class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> vec;
    auto const processor = [&](auto root) { vec.push_back(root->val); };
    postorder(root, processor);
    return vec;
  }
};
