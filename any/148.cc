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
  ListNode *sortList(ListNode *head) {
    if(head == nullptr or head->next == nullptr) return head;
    ListNode* prev = nullptr, *slow = head, *fast = head;
    while(fast and fast->next){
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;
    auto l1 = sortList(head);
    auto l2 = sortList(slow);
    return merge(l1, l2);
  }

  ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode* l = new ListNode(0);
    auto p = l;
    while(l1 and l2){
      if(l1->val < l2->val){
        p->next = l1;
        l1 = l1->next;
      }else{
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    if(l1){
      p->next = l1;
    }
    if(l2){
      p->next = l2;
    }
    return l->next;
  }
};
