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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr)
      return nullptr;
    else if (root == p)
      return p;
    else if (root == q)
      return q;
    auto left_ans = lowestCommonAncestor(root->left, p, q);
    auto right_ans = lowestCommonAncestor(root->right, p, q);
    if (left_ans && right_ans)
      return root;
    else if (left_ans)
      return left_ans;
    else
      return right_ans;
  }
};
