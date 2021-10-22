#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
      if(root == nullptr) return {};
      queue<TreeNode*> q;
      q.push(root);
      vector<vector<int>> vec;
      while(not empty(q)){
        int n = size(q);
        vector<int> tmp;
        while(n--){
          auto top = q.front();
          q.pop();
          if(top->left) q.push(top->left);
          if(top->right) q.push(top->right);
          tmp.push_back(top->val);
        }
        vec.push_back(tmp);
      }
      return vec;
    }
};

