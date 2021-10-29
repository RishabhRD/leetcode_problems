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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    auto cur = dummy;
    int carry = 0;
    while (l1 and l2) {
      int sum = carry + l1->val + l2->val;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      carry = sum / 10;
      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1) {
      int sum = carry + l1->val;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      carry = sum / 10;
      l1 = l1->next;
    }
    while (l2) {
      int sum = carry + l2->val;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      carry = sum / 10;
      l2 = l2->next;
    }
    if(carry){
      cur->next = new ListNode(carry);
    }
    return dummy->next;
  }
};
