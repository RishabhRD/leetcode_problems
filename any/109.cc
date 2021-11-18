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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};


auto size(ListNode* head){
  int n = 0;
  while(head){
    n++;
    head = head->next;
  }
  return n;
}

TreeNode* build_tree(int low, int high, ListNode*& cur){
  if(low > high) return nullptr;
  auto mid = (low + high) / 2;
  TreeNode* node = new TreeNode;
  node->left = build_tree(low, mid - 1, cur);
  node->val = cur->val;
  cur = cur->next;
  node->right = build_tree(mid + 1, high, cur);
  return node;
}


class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    const auto n = size(head);
    return build_tree(0, size(head) - 1, head);
  }
};
