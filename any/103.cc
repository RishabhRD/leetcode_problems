#include <list>
#include <queue>
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

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
    queue<TreeNode *> q;
    q.push(root);
    bool l2r = false;
    while (not empty(q)) {
      auto sz = size(q);
      vector<int> vec;
      while (sz--) {
        auto top = q.front();
        vec.push_back(top->val);
        q.pop();
        if (top->left) q.push(top->left);
        if (top->right) q.push(top->right);
      }
      l2r = !l2r;
      if (!l2r) std::reverse(begin(vec), end(vec));
      result.push_back(std::move(vec));
    }
    return result;
  }
};
