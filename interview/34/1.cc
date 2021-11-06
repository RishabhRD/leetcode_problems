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

void traverse(TreeNode *root, vector<int> &vec) {
  if (root == nullptr) return;
  traverse(root->left, vec);
  vec.push_back(root->val);
  traverse(root->right, vec);
}

bool exists(vector<int>& vec, int k){
  int low = 0;
  int high = size(vec) - 1;
  while(low < high){
    if(vec[low] + vec[high] == k) return true;
    else if(vec[low] + vec[high] < k) low++;
    else high--;
  }
  return false;
}

class Solution {
public:
  bool findTarget(TreeNode *root, int k) {
    vector<int> vec;
    traverse(root, vec);
    return exists(vec, k);
  }
};
