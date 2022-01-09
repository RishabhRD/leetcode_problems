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

int tree_sum_cached(TreeNode *root, unordered_map<int, int> &mp) {
  if (root == nullptr) return 0;
  int left_sum = tree_sum_cached(root->left, mp);
  int right_sum = tree_sum_cached(root->right, mp);
  int cur_sum = left_sum + right_sum + root->val;
  mp[cur_sum]++;
  return cur_sum;
}

class Solution {
public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> tree_sums;
    tree_sum_cached(root, tree_sums);
    auto max_count =
      max_element(cbegin(tree_sums), cend(tree_sums), [](auto p1, auto p2) {
        return p1.second < p2.second;
      })->second;
    vector<int> res;
    for (auto [k, v] : tree_sums) {
      if (v == max_count) res.push_back(k);
    }
    return res;
  }
};
