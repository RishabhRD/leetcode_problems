#include <stack>
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


class BSTIterator {
  stack<TreeNode *> st;

public:
  BSTIterator(TreeNode *root) { push_all(root); }

  int next() {
    auto top = st.top();
    st.pop();
    push_all(top->right);
    return top->val;
  }

  bool hasNext() { return !empty(st); }

private:
  void push_all(TreeNode *root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }
};
