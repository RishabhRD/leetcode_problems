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
    if (root == nullptr) return {};
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    bool r2l = false;
    while (not empty(q)) {
      auto sz = size(q);
      vector<int> cur;
      while (sz--) {
        auto top = q.front();
        q.pop();
        cur.push_back(top->val);
        if (top->left) q.push(top->left);
        if (top->right) q.push(top->right);
      }
      if (r2l) reverse(begin(cur), end(cur));
      res.push_back(move(cur));
      r2l = !r2l;
    }
    return res;
  }
};
