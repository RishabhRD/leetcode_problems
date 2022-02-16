#include <sstream>
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *to_treenode(string const &str) {
  if (str == "X") return nullptr;
  return new TreeNode(stoi(str));
}

TreeNode *to_treenode(istringstream &in) {
  string str;
  in >> str;
  return to_treenode(str);
}

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    ostringstream str;
    while (not empty(q)) {
      auto top = q.front();
      q.pop();
      if (top == nullptr) {
        str << " X";
      } else {
        str << " " << to_string(top->val);
        q.push(top->left);
        q.push(top->right);
      }
    }
    return str.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    istringstream in(data);
    queue<TreeNode *> q;
    auto root = to_treenode(in);
    if (root) q.push(root);
    TreeNode *const head = empty(q) ? nullptr : q.front();
    while (not empty(q)) {
      auto top = q.front();
      q.pop();
      auto left = to_treenode(in);
      auto right = to_treenode(in);
      top->left = left;
      top->right = right;
      if (left) q.push(left);
      if (right) q.push(right);
    }
    return head;
  }
};
