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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
      if(head == nullptr) return true;
      stack<int> st;
      auto slow = head;
      auto fast = head;
      while(fast and fast->next){
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
      }
      if(fast) slow = slow->next;
      while(slow){
        auto val = slow->val;
        auto top = st.top();
        st.pop();
        if(val != top) return false;
        slow = slow->next;
      }
      return true;
    }
};
