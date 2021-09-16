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

auto traverse(TreeNode* root) -> vector<vector<int>>{
  if(root == nullptr) return {};
  vector<TreeNode*> q;
  vector<vector<int>> res;
  q.push_back(root);
  bool r2l = false;
  while(not empty(q)){
    vector<int> new_vec;
    vector<TreeNode*> next_vec;
    auto push = [&](TreeNode* ele){
      if(ele) next_vec.push_back(ele);
    };
    for(int i = size(q) - 1; i >= 0; i--){
      auto ele = q[i];
      new_vec.push_back(ele->val);
      if(r2l){
        push(ele->right);
        push(ele->left);
      }else{
        push(ele->left);
        push(ele->right);
      }
    }
    r2l = !r2l;
    res.push_back(new_vec);
    q = std::move(next_vec);
  }
  return res;
}

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    return traverse(root);
  }
};
