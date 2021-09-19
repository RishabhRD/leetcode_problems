#include <unordered_set>>
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

template<typename Func> void traverse(TreeNode *&root, Func &&func) {
  if (root == nullptr) { return; }
  traverse(root->left, func);
  traverse(root->right, func);
  func(root);
}

class Solution {
public:
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    unordered_set<int> st{ cbegin(to_delete), cend(to_delete) };
    vector<TreeNode *> res;
    traverse(root, [&](TreeNode *&root) {
      if (st.find(root->val) != end(st)) {
        if (root->right) res.push_back(root->right);
        if (root->left) res.push_back(root->left);
        root = nullptr;
      }
    });
    if(root) res.push_back(root);
    return res;
  }
};
