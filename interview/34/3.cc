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

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if(head == nullptr) return nullptr;
    auto cur = head;
    while(cur){
      auto new_node = new Node(cur->val);
      new_node->random = cur->random;
      auto next_node = cur->next;
      new_node->next = next_node;
      cur->next = new_node;
      cur = next_node;
    }
    cur = head->next;
    while(cur){
      if(cur->random)
        cur->random = cur->random->next;
      if(cur->next)
        cur = cur->next->next;
      else
        cur = nullptr;
    }
    cur = head;
    auto dummy_head = new Node(0);
    auto dummy = dummy_head;
    while(cur){
      auto next_orig = cur->next->next;
      auto next_new = cur->next;
      cur->next = next_orig;
      dummy->next = next_new;
      dummy = dummy->next;
      cur = next_orig;
    }
    return dummy_head->next;
  }
};
