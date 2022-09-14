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
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    while (head and head->val == val) head = head->next;

    ListNode* prev = nullptr;
    auto cur = head;
    while (cur) {
      if (cur->val == val) {
        prev->next = cur->next;
      } else {
        prev = cur;
      }
      cur = cur->next;
    }
    return head;
  }
};
