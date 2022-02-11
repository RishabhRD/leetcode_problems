#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    if (head->next == nullptr) return false;
    auto slow = head;
    auto fast = head->next;
    while (fast and fast->next) {
      if (slow == fast) return true;
      slow = slow->next;
      fast = fast->next->next;
    }
    return false;
  }
};
