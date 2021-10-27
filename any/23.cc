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
    auto cmp_nodes = [](ListNode* n1, ListNode* n2){
      return n1->val > n2->val;
    };
    using lnp = ListNode*;
    priority_queue<lnp, vector<lnp>, decltype(cmp_nodes)> pq(cmp_nodes);
    for(auto ln_head : lists){
      while(ln_head){
        pq.push(ln_head);
        ln_head = ln_head->next;
      }
    }
    lnp dummy = new ListNode;
    auto cur = dummy;
    while(not empty(pq)){
      auto top = pq.top();
      pq.pop();
      cur->next = top;
      top->next = nullptr;
      cur = cur->next;
    }
    return dummy->next;
  }
};
