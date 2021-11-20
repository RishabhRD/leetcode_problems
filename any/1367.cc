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

bool is_path(ListNode *head, TreeNode *root) {
  if (head == nullptr) return true;
  if (root == nullptr) return false;
  return head->val == root->val
         && (is_path(head->next, root->left)
             || is_path(head->next, root->right));
}

bool is_sub_path(ListNode *head, TreeNode *root) {
  if (head == nullptr) return true;
  if (root == nullptr) return false;
  return is_path(head, root) || is_sub_path(head, root->left)
         || is_sub_path(head, root->right);
}

class Solution {
public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    return is_sub_path(head, root);
  }
};
