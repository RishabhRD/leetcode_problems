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
  Node *left, *right;
};

bool is_leaf(Node *root) {
  return root->left == nullptr and root->right == nullptr;
}

void add_left(Node *root, vector<int> &ans) {
  if (root == nullptr) return;
  while (!is_leaf(root)) {
    ans.push_back(root->data);
    if (root->left)
      root = root->left;
    else
      root = root->right;
  }
}

void add_right(Node *root, vector<int> &ans) {
  if (root == nullptr) return;
  if (is_leaf(root)) return;
  if (root->right)
    add_right(root->right, ans);
  else
    add_right(root->left, ans);
  ans.push_back(root->data);
}

void add_leaves(Node *root, vector<int> &ans) {
  if (root == nullptr) return;
  add_leaves(root->left, ans);
  if (is_leaf(root)) ans.push_back(root->data);
  add_leaves(root->right, ans);
}

class Solution {
public:
  vector<int> boundary(Node *root) {
    if (root == nullptr) return {};
    vector<int> ans;
    ans.push_back(root->data);
    add_left(root->left, ans);
    if (not is_leaf(root)) add_leaves(root, ans);
    add_right(root->right, ans);
    return ans;
  }
};
