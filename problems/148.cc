#include <memory>
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

ListNode *merge(ListNode *l1, ListNode *l2) {
  auto l_head = new ListNode;
  auto l = l_head;
  auto add = [&](auto &lst) {
    l->next = lst;
    l = lst;
    lst = lst->next;
  };
  while (l1 and l2) {
    if (l1->val < l2->val)
      add(l1);
    else
      add(l2);
  }
  while (l1) add(l1);
  while (l2) add(l2);
  return l_head->next;
}

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (head == nullptr or head->next == nullptr) return head;
    ListNode *prev = nullptr;
    auto slow = head;
    auto fast = head;
    while (fast and fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    auto other = prev->next;
    prev->next = nullptr;
    auto l1 = sortList(head);
    auto l2 = sortList(other);
    return merge(l1, l2);
  }
};
