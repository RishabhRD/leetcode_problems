#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

using ll = long long;

void fill_parent(TreeNode *cur, TreeNode *parent,
                 std::unordered_map<TreeNode *, TreeNode *> &mp) {
  if (cur == nullptr) return;
  mp[cur] = parent;
  fill_parent(cur->left, cur, mp);
  fill_parent(cur->right, cur, mp);
}

void fill_sum(TreeNode *cur, std::unordered_map<TreeNode *, ll> &mp) {
  ll sum = 0;
  if (cur->left) {
    sum += cur->left->val;
    fill_sum(cur->left, mp);
  }

  if (cur->right) {
    sum += cur->right->val;
    fill_sum(cur->right, mp);
  }

  mp[cur] = sum;
}

auto get_depth_sum(TreeNode *root) {
  std::unordered_map<ll, ll> sum_mp;
  std::queue<TreeNode *> q;
  q.push(root);

  ll cur_depth = 0;
  while (q.size()) {
    auto sz = q.size();
    ll sum = 0;
    while (sz--) {
      auto const top = q.front();
      q.pop();
      sum += top->val;
      if (top->left) {
        q.push(top->left);
      }
      if (top->right) {
        q.push(top->right);
      }
    }
    sum_mp[cur_depth] = sum;
    ++cur_depth;
  }
  return sum_mp;
}

void replace(TreeNode *root,
             std::unordered_map<TreeNode *, TreeNode *> parent_of,
             std::unordered_map<TreeNode *, ll> parent_sum,
             std::unordered_map<ll, ll> depth_sum) {
  std::queue<TreeNode *> q;
  q.push(root);

  ll cur_depth = 0;
  while (q.size()) {
    auto sz = q.size();
    ll sum = 0;
    while (sz--) {
      auto const top = q.front();
      q.pop();
      if (parent_of[top] == nullptr) {
        top->val = 0;
      } else {
        top->val = depth_sum[cur_depth] - parent_sum[parent_of[top]];
      }
      if (top->left) {
        q.push(top->left);
      }
      if (top->right) {
        q.push(top->right);
      }
    }
    ++cur_depth;
  }
}

class Solution {
 public:
  TreeNode *replaceValueInTree(TreeNode *root) {
    std::unordered_map<TreeNode *, TreeNode *> parent_of;
    fill_parent(root, nullptr, parent_of);
    std::unordered_map<TreeNode *, ll> parent_sum;
    fill_sum(root, parent_sum);
    auto depth_sum = get_depth_sum(root);
    replace(root, parent_of, parent_sum, depth_sum);
    return root;
  }
};
