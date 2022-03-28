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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};

template<typename Iter, typename PIter>
TreeNode *create_tree(Iter low, Iter high, PIter &preorder) {
  if (low >= high) return nullptr;
  auto const node_val = *preorder;
  auto const node_iter = std::find(low, high, node_val);
  auto new_node = new TreeNode(node_val);
  preorder++;
  new_node->left = create_tree(low, node_iter, preorder);
  new_node->right = create_tree(next(node_iter), high, preorder);
  return new_node;
}

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    auto p_iter = begin(preorder);
    return create_tree(begin(inorder), end(inorder), p_iter);
  }
};
