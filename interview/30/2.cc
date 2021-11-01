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
  vector<TreeNode *> st;

public:
  BSTIterator(TreeNode *root) { push_left(root); }

  int next() {
    auto top = st.back();
    st.pop_back();
    push_left(top->right);
    cout << top->val << endl;
    return top->val;
  }

  bool hasNext() { return not empty(st); }

private:
  void push_left(TreeNode *root) {
    while (root) {
      st.push_back(root);
      root = root->left;
    }
  }
};
