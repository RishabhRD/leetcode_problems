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

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
    : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (root == nullptr) return root;
    queue<Node *> q;
    q.push(root);
    while (not empty(q)) {
      auto sz = size(q);
      Node *last = nullptr;
      while (sz--) {
        auto top = q.front();
        q.pop();
        top->next = nullptr;
        if (last) last->next = top;
        if (top->left) q.push(top->left);
        if (top->right) q.push(top->right);
        last = top;
      }
    }
    return root;
  }
};
