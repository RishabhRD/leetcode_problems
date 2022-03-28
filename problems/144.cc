template<typename Func> void traverse(TreeNode *root, Func &&func) {
  if (root == nullptr) return;
  func(root);
  traverse(root->left, func);
  traverse(root->right, func);
}
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    traverse(root, [&](auto x) { vec.push_back(x->val); });
    return vec;
        
    }
};
