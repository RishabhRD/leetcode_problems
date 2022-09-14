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

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    auto const left_depth = minDepth(root->left);
    auto const right_depth = minDepth(root->right);
    return 1 + ((std::min(left_depth, right_depth) == 0)
                    ? std::max(left_depth, right_depth)
                    : std::min(left_depth, right_depth));
  }
};
