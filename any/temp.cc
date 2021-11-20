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
  Node *left;
  Node *right;
  Node *random;
};

void build_tree(Node *root,
  Node *&new_root,
  unordered_map<Node *, Node *> &mp) {
  if (root == nullptr) {
    new_root = nullptr;
    return;
  }
  new_root = new Node(root->data);
  mp[root] = new_root;
  build_tree(root->left, new_root->left, mp);
  build_tree(root->right, new_root->right, mp);
}

void build_random(Node *root, unordered_map<Node *, Node *> &mp) {
  if (root == nullptr) return;
  mp[root]->random = mp[root->random];
  build_random(root->left, mp);
  build_random(root->right, mp);
}

class Solution {
public:
  Node *cloneTree(Node *root) {
    Node *new_root = nullptr;
    unordered_map<Node *, Node *> mp;
    build_tree(root, new_root, mp);
    build_random(root, mp);
    return new_root;
  }
};
