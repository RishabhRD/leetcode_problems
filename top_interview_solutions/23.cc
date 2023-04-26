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
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode* head = new ListNode();
    ListNode* tail = head;
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(
        cmp);

    for (auto l : lists) {
      if (l) pq.push(l);
    }

    while (pq.size()) {
      auto const top = pq.top();
      pq.pop();
      if (top->next) pq.push(top->next);
      tail->next = top;
      tail = top;
    }

    return head->next;
  }
};
