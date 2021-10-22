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

TreeNode *create_bst(vector<int> &nums, int low, int high) {
  if (low > high) return nullptr;
  int mid = (low + high) / 2;
  return new TreeNode(
    nums[mid], create_bst(nums, low, mid - 1), create_bst(nums, mid + 1, high));
}

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return create_bst(nums, 0, size(nums) - 1);
  }
};
