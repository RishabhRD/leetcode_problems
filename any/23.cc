#include <queue>
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto cmp_nodes = [](auto n1, auto n2) { return n1->val > n2->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp_nodes)> pq(
      cmp_nodes);
    for (auto list : lists) {
      if (list) pq.push(list);
    }
    auto lst_head = new ListNode;
    auto lst = lst_head;
    while (not empty(pq)) {
      auto top = pq.top();
      pq.pop();
      lst->next = top;
      lst = top;
      top = top->next;
      if (top) pq.push(top);
    }
    return lst_head->next;
  }
};
