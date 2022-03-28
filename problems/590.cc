
template<typename Func> void traverse(Node *root, Func &&func) {
  if (root == nullptr) return;
  for (auto n : root->children) { traverse(n, func); }
  func(root);
}

class Solution {
public:
  vector<int> postorder(Node *root) {
    vector<int> vec;
    traverse(root, [&](auto n) { vec.push_back(n->val); });
    return vec;
  }
};
