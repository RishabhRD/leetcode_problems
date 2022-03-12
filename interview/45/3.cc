#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *to_treenode(istringstream &in) {
  string str;
  in >> str;
  if (str == "X") {
    return nullptr;
  } else {
    return new TreeNode(stoi(str));
  }
}

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    ostringstream os;
    queue<TreeNode *> q;
    q.push(root);
    while (not empty(q)) {
      auto top = q.front();
      q.pop();
      if (top == nullptr)
        os << "X\n";
      else
        os << to_string(top->val) + '\n';
      if (top) {
        q.push(top->left);
        q.push(top->right);
      }
    }
    return os.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    istringstream in{ data };
    queue<TreeNode *> q;
    auto const head = to_treenode(in);
    if (head) q.push(head);
    while (not empty(q)) {
      auto top = q.front();
      q.pop();
      auto const left = to_treenode(in);
      auto const right = to_treenode(in);
      top->left = left;
      top->right = right;
      if (left) q.push(left);
      if (right) q.push(right);
    }
    return head;
  }
};
