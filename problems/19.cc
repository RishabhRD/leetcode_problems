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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto fast = head;
    for (int i = 0; i < n; i++) fast = fast->next;
    ListNode *prev = nullptr;
    auto slow = head;
    while (fast) {
      prev = slow;
      slow = slow->next;
      fast = fast->next;
    }
    if (prev)
      prev->next = slow->next;
    else
      head = slow->next;
    return head;
  }
};
