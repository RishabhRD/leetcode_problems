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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
      queue<Node*> q;
      if(root)
        q.push(root);
      while(not empty(q)){
        int n = size(q);
        for(int i = 0; i < n - 1; i++){
          auto top = q.front();
          q.pop();
          top->next = q.front();
          if(top->left) q.push(top->left);
          if(top->right) q.push(top->right);
        }
        auto top = q.front();
        q.pop();
        top->next = nullptr;
        if(top->left) q.push(top->left);
        if(top->right) q.push(top->right);
      }
      return root;
    }
};

int main(){
  Node n1(1);
  Node n2(2);
  Node n3(3);
  n1.left = &n2;
  n2.right = &n3;
  Solution sol;
  sol.connect(&n1);
}
