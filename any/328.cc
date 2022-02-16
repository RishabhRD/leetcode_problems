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
  ListNode *oddEvenList(ListNode *head) {
    auto even_head = new ListNode;
    auto odd_head = new ListNode;
    auto even = even_head;
    auto odd = odd_head;
    bool odd_turn = true;
    while (head) {
      auto next_node = head->next;
      if (odd_turn) {
        odd->next = head;
        odd = odd->next;
      } else {
        even->next = head;
        even = even->next;
      }
      odd_turn = !odd_turn;
      head = next_node;
    }
    odd->next = even_head->next;
    even->next = nullptr;
    return odd_head->next;
  }
};
