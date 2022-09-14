#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

auto lenof(ListNode *head) {
  int len = 0;
  while (head) {
    ++len;
    head = head->next;
  }
  return len;
}

auto intersect_equal(ListNode *headA, ListNode *headB) -> ListNode * {
  while (headA and headB) {
    if (headA == headB) return headA;
    headA = headA->next;
    headB = headB->next;
  }
  return nullptr;
}

auto increment(ListNode *lst, int k) {
  for (int i = 0; i < k; ++i) {
    lst = lst->next;
  }
  return lst;
}

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto const len_a = lenof(headA);
    auto const len_b = lenof(headB);
    if (len_a > len_b) {
      headA = increment(headA, len_a - len_b);
    } else {
      headB = increment(headB, len_b - len_a);
    }
    return intersect_equal(headA, headB);
  }
};
