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

auto map_nodes(std::vector<TreeNode *> const &pre_level,
               std::vector<TreeNode *> const &cur_level) {
  int i = 0;
  for (int j = 0; j < std::size(cur_level); j += 2) {
    pre_level[i]->left = cur_level[j];
    pre_level[i]->right = cur_level[j + 1];
    ++i;
  }
}

class Solution {
 public:
  TreeNode *reverseOddLevels(TreeNode *root) {
    std::vector<TreeNode *> pre_level{root};
    bool to_reverse = true;
    while (not std::empty(pre_level)) {
      std::vector<TreeNode *> cur_level;
      for (auto node : pre_level) {
        if (node->left) {
          cur_level.push_back(node->left);
          cur_level.push_back(node->right);
        }
      }
      if (to_reverse) {
        std::reverse(std::begin(cur_level), std::end(cur_level));
        map_nodes(pre_level, cur_level);
      } else {
        std::reverse(std::begin(pre_level), std::end(pre_level));
        map_nodes(pre_level, cur_level);
      }
      pre_level = std::move(cur_level);
      to_reverse = !to_reverse;
    }
    return root;
  }
};
