#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

auto btree_create(int n, unordered_map<int, vector<TreeNode *>> &cache)
  -> vector<TreeNode *> {
  if (n == 1) { return { new TreeNode{} }; }
  if (cache.find(n) != cache.end()) { return cache.at(n); }
  vector<TreeNode *> res;
  for (int left = 1; left < n; left += 2) {
    auto left_trees = btree_create(left, cache);
    auto right_trees = btree_create(n - 1 - left, cache);
    for (auto left_nodes : left_trees) {
      for (auto right_nodes : right_trees) {
        TreeNode *root = new TreeNode;
        root->left = left_nodes;
        root->right = right_nodes;
        res.push_back(root);
      }
    }
  }
  return cache[n] = res;
}

class Solution {
public:
  vector<TreeNode *> allPossibleFBT(int n) {
    unordered_map<int, vector<TreeNode *>> cache;
    return btree_create(n, cache);
  }
};
