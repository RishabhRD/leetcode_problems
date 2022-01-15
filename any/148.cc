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

auto partition_middle_list(ListNode *head) {
  auto slow = head;
  auto fast = head;
  ListNode *prev = nullptr;
  while (fast and fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = nullptr;
  return slow;
}

auto merge(ListNode *first_list, ListNode *second_list) {
  auto pseudo_head = make_unique<ListNode>();
  auto cur = pseudo_head.get();
  while (first_list and second_list) {
    if (first_list->val < second_list->val) {
      cur->next = first_list;
      first_list = first_list->next;
    } else {
      cur->next = second_list;
      second_list = second_list->next;
    }
    cur = cur->next;
  }
  if (first_list)
    cur->next = first_list;
  else if (second_list)
    cur->next = second_list;
  return pseudo_head->next;
}

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (head == nullptr or head->next == nullptr) return head;
    auto second_half = partition_middle_list(head);
    auto first_list = sortList(head);
    auto second_list = sortList(second_half);
    return merge(first_list, second_list);
  }
};
