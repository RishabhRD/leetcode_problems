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

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

template<typename Func> void traverse(Node *root, Func &&func) {
  if (root == nullptr) return;
  func(root);
  for (auto n : root->children) { traverse(n, func); }
}

class Solution {
public:
  vector<int> preorder(Node *root) {
    vector<int> vec;
    traverse(root, [&](auto n) { vec.push_back(n->val); });
    return vec;
  }
};
