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

using ll = long long;

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* ans_head = new ListNode;
    ListNode* ans_tail = ans_head;

    ll sz = 0;
    {
      ListNode* cur = head;
      while (cur) {
        ++sz;
        cur = cur->next;
      }
    }

    ListNode* cur = head;
    ll done = 0;
    while (cur != nullptr) {
      if (sz - done < k) {
        ans_tail->next = cur;
        ans_tail = nullptr;
        cur = nullptr;
      } else {
        ListNode* in_head = nullptr;
        ListNode* in_tail = nullptr;
        for (ll i = 0; i < k && cur; ++i) {
          ++done;
          if (!in_tail) {
            in_tail = cur;
          }
          auto const next = cur->next;
          cur->next = in_head;
          in_head = cur;
          cur = next;
        }
        ans_tail->next = in_head;
        ans_tail = in_tail;
      }
    }
    return ans_head->next;
  }
};
