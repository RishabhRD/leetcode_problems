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

template<typename Iter> TreeNode *sorted_bst(Iter begin, Iter end) {
  if (begin >= end) return nullptr;
  auto const count = distance(begin, end);
  auto const step = count / 2;
  Iter mid = begin;
  advance(mid, step);
  auto tree_node = new TreeNode(*mid);
  tree_node->left = sorted_bst(begin, mid);
  tree_node->right = sorted_bst(next(mid), end);
  return tree_node;
}

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return sorted_bst(begin(nums), end(nums));
  }
};
