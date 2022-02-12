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

auto reverse(ListNode *head) {
  ListNode *new_head = nullptr;
  while (head) {
    auto next_node = head->next;
    head->next = new_head;
    new_head = head;
    head = next_node;
  }
  return new_head;
}

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr) return true;
    auto slow = head;
    auto fast = head;
    ListNode *prev = nullptr;
    while (fast and fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    auto l1 = head;
    auto l2 = reverse(slow);
    while (l1 and l2) {
      if (l1->val != l2->val) return false;
      l1 = l1->next;
      l2 = l2->next;
    }
    return true;
  }
};
