#include <utility>
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

template<typename Func> void kth_ele(TreeNode *root, Func &&func) {
  if (root == nullptr) { return; }
  kth_ele(root->left, func);
  func(root->val);
  kth_ele(root->right, func);
}

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    int ele;
    auto func = [&, cur = 1](int num) mutable {
      if (cur == k) ele = num;
      cur++;
    };
    kth_ele(root, func);
    return ele;
  }
};
