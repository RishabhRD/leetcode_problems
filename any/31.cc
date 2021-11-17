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

class Solution {
public:
  void nextPermutation(vector<int> &arr) {
    const int n = size(arr);
    int i1 = -1;
    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] < arr[i + 1]) {
        i1 = i;
        break;
      }
    }
    if (i1 != -1) {
      int i2 = -1;
      for (int i = n - 1; i > i1; i--) {
        if (arr[i] > arr[i1]) {
          i2 = i;
          break;
        }
      }
      swap(arr[i1], arr[i2]);
    }
    reverse(begin(arr) + i1 + 1, end(arr));
  }
};


struct Node {
  int data;
  Node *left, *right;
};

bool is_leaf(const Node* root){
  return root->left == nullptr and root->right == nullptr;
}

void add_left(const Node* root, vector<int>& ans){
  if(not root) return;
  while(!is_leaf(root)){
    ans.push_back(root->data);
    if(root->left)
      root = root->left;
    else
      root = root->right;
  }
}

void add_right(const Node* root, vector<int>& ans){
  if(not root or is_leaf(root)){
    return;
  }
  if(root->right)
    add_right(root->right, ans);
  else
    add_right(root->left, ans);
  ans.push_back(root->data);
}

void add_leaves(const Node* root, vector<int>& ans){
  if(root == nullptr) return;
  add_leaves(root->left, ans);
  if(is_leaf(root))
    ans.push_back(root->data);
  add_leaves(root->right, ans);
}

class Solution {
public:
  vector<int> boundary(Node *root) {
    if(root == nullptr) return {};
    vector<int> ans;
    ans.push_back(root->data);
    add_left(root->left, ans);
    if(!is_leaf(root)){
      add_leaves(root, ans);
    }
    add_right(root->right, ans);
    return ans;
  }
};
