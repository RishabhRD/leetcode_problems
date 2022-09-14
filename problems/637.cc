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

class Solution {
 public:
  std::vector<double> averageOfLevels(TreeNode *root) {
    std::vector<double> level_sum_arr;

    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      auto const cur_level_size = q.size();
      double cur_sum = 0;
      auto n = cur_level_size;
      while (n--) {
        auto top = q.front();
        q.pop();
        cur_sum += top->val;
        if (top->left) q.push(top->left);
        if (top->right) q.push(top->right);
      }
      level_sum_arr.push_back(cur_sum / cur_level_size);
    }
    return level_sum_arr;
  }
};
