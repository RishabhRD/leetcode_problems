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

struct Node {
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

pair<Node *, Node *> dll(Node *root) {
  pair<Node *, Node *> res = { nullptr, nullptr };
  if (root->left) {
    auto left_ans = dll(root->left);
    left_ans.second->right = root;
    root->left = left_ans.second;
    res.first = left_ans.first;
  } else {
    res.first = root;
  }
  if (root->right) {
    auto right_ans = dll(root->right);
    right_ans.first->left = root;
    root->right = right_ans.first;
    res.second = right_ans.second;
  } else {
    res.second = root;
  }
  return res;
}

class Solution {
public:
  Node *bToDLL(Node *root) {
    return dll(root).first;
  }
};
