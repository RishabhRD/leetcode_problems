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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template <typename F>
void traverse(TreeNode* root, F&& f){
  if(root == nullptr) return;
  traverse(root->left, f);
  f(root);
  traverse(root->right, std::forward<F>(f));
}

auto get_fill_vec(vector<int>& vec){
  return [&](auto e){
    vec.push_back(e->val);
  };
}

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      vector<int> left_list;
      vector<int> right_list;
      traverse(root1, get_fill_vec(left_list));
      traverse(root2, get_fill_vec(right_list));
      vector<int> res;
      merge(cbegin(left_list), cend(left_list), cbegin(right_list), cend(right_list), back_inserter(res));
      return res;
    }
};
