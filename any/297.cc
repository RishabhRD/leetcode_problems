#include <sstream>
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  string serialize(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    stringstream str;
    while(not empty(q)){
      auto top = q.front();
      q.pop();
      if(top == nullptr){
        str << " X";
      }else{
        str << " " << to_string(top->val);
        q.push(top->left);
        q.push(top->right);
      }
    }
    return str.str();
  }

  TreeNode *deserialize(string data) {
    stringstream stream(data);
    TreeNode* root = nullptr;
    queue<reference_wrapper<TreeNode*>> q;
    q.push(root);
    while(not empty(q)){
      auto& top = q.front().get();
      q.pop();
      string cur_str;
      stream >> cur_str;
      if(cur_str == "X"){
        top = nullptr;
      }else{
        top = new TreeNode(stoi(cur_str.c_str()));
        q.push(top->left);
        q.push(top->right);
      }
    }
    return root;
  }
};
