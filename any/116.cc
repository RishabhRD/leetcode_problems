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
      const int n = size(q);
      auto prev = q.front();
      q.pop();
      if (prev->left) { q.push(prev->left); }
      if (prev->right) { q.push(prev->right); }
      for (int i = 1; i < n; i++) {
        auto cur = q.front();
        q.pop();
        if (cur->left) { q.push(cur->left); }
        if (cur->right) { q.push(cur->right); }
        prev->next = cur;
        prev = cur;
      }
      prev->next = nullptr;
    }
    return root;
  }
};
