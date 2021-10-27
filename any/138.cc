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
    auto cur_node = head;
    while(cur_node){
      Node* new_node = new Node(cur_node->val);
      new_node->random = cur_node->random;
      cur_node = exchange(cur_node->next, new_node);
      new_node->next = cur_node;
    }
    cur_node = head->next;
    while(cur_node){
      if(cur_node->random){
        cur_node->random = cur_node->random->next;
      }
      if(cur_node->next)
        cur_node = cur_node->next->next;
      else
        cur_node = nullptr;
    }
    auto dummy = new Node(0);
    auto dummy_cur = dummy;
    cur_node = head;
    while(cur_node){
      dummy_cur->next = cur_node->next;
      dummy_cur = dummy_cur->next;
      cur_node->next = cur_node->next->next;
      dummy_cur->next = nullptr;
      cur_node = cur_node->next;
    }
    return dummy->next;
  }
};
