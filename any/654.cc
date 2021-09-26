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


class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      vector<TreeNode*> res;
      for(int x : nums){
        auto node = new TreeNode(x);
        while(not empty(res) and res.back()->val < x){
          node->left = res.back();
          res.pop_back();
        }
        if(not empty(res)){
          res.back()->right = node;
        }
        res.push_back(node);
      }
      return res.front();
    }
};
