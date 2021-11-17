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
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    auto cur = head;
    while(cur){
      Node* new_node = new Node(cur->val);
      Node* next_node = cur->next;
      new_node->next = next_node;
      new_node->random = cur->random;
      cur->next = new_node;
      cur = next_node;
    }
    cur = head;
    while(cur){
      auto new_node = cur->next;
      auto next_node = new_node->next;
      if(new_node->random)
        new_node->random = new_node->random->next;
      cur = next_node;
    }
    auto dummy = new Node(0);
    auto dummy_cur = dummy;
    cur = head;
    while(cur){
      auto new_node = cur->next;
      auto next_node = new_node->next;
      cur->next = next_node;
      dummy_cur->next = new_node;
      dummy_cur = new_node;
      cur = next_node;
    }
    return dummy->next;
  }
};
