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

enum class node_t { leaf, covered, camera };

node_t dfs(TreeNode *root, int &total_camera) {
  if (root == nullptr) return node_t::covered;
  auto left_t = dfs(root->left, total_camera);
  auto right_t = dfs(root->right, total_camera);
  if (left_t == node_t::covered and right_t == node_t::covered)
    return node_t::leaf;
  if (left_t == node_t::leaf or right_t == node_t::leaf) {
    ++total_camera;
    return node_t::camera;
  }
  return node_t::covered;
}

class Solution {
 public:
  int minCameraCover(TreeNode *root) {
    int total_camera = 0;
    auto root_t = dfs(root, total_camera);
    return (root_t == node_t::leaf ? 1 : 0) + total_camera;
  }
};
