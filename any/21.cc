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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    auto const res_head = new ListNode;
    auto res = res_head;
    auto add = [&](auto &list) {
      res->next = list;
      res = list;
      list = list->next;
    };
    while (list1 and list2) {
      if (list1->val < list2->val)
        add(list1);
      else
        add(list2);
    }
    while (list1) add(list1);
    while (list2) add(list2);
    return res_head->next;
  }
};
