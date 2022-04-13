#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

using Iter = vector<int>::const_iterator;

TreeNode *create_tree(Iter low, Iter high, Iter &cur_p,
                      unordered_map<int, Iter> const &mp) {
  if (low == high) return nullptr;
  auto p_copy = cur_p;
  auto node = new TreeNode(*p_copy);
  ++cur_p;
  node->left = create_tree(low, mp.at(*p_copy), cur_p, mp);
  node->right = create_tree(next(mp.at(*p_copy)), high, cur_p, mp);
  return node;
}

class Solution {
 public:
  TreeNode *buildTree(vector<int> const &preorder, vector<int> const &inorder) {
    unordered_map<int, Iter> inorder_idx_mp;
    for (auto itr = cbegin(inorder); itr != cend(inorder); ++itr) {
      inorder_idx_mp[*itr] = itr;
    }
    auto preorder_begin = cbegin(preorder);
    return create_tree(cbegin(inorder), cend(inorder), preorder_begin,
                       inorder_idx_mp);
  }
};
