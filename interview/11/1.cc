#include <stack>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
      vector<int> vec;
      for(auto itr = head; itr; itr = itr->next){
        vec.push_back(itr->val);
      }
      stack<int> st;
      for(int i = vec.size() - 1; i >= 0; i--){
        auto val = vec[i];
        while(not empty(st) and st.top() <= val){
          st.pop();
        }
        vec[i] = empty(st) ? 0 : st.top();
        st.push(val);
      }
      return vec;
    }
};
