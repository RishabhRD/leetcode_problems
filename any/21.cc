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

void add(ListNode *&head, ListNode *&tail, ListNode *lst) {
  if (not head) {
    head = lst;
    tail = lst;
  } else {
    tail->next = lst;
    tail = tail->next;
  }
}

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr, *tail = nullptr;
    while (l1 and l2) {
      if (l1->val < l2->val) {
        auto tmp1 = l1;
        l1 = l1->next;
        add(head, tail, tmp1);
      } else {
        auto tmp2 = l2;
        l2 = l2->next;
        add(head, tail, tmp2);
      }
    }
    while (l1) {
      auto tmp1 = l1;
      l1 = l1->next;
      add(head, tail, tmp1);
    }
    while (l2) {
      auto tmp2 = l2;
      l2 = l2->next;
      add(head, tail, tmp2);
    }
    return head;
  }
};
