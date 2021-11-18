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
  Node *prev;
  Node *next;
  Node *child;
};

auto flatten_tail(Node *head) {
  if (head == nullptr) return head;
  if (head->child == nullptr) {
    if (head->next) return flatten_tail(head->next);
    return head;
  }
  auto next_node = head->next;
  auto child_node = head->child;
  head->child = nullptr;
  auto child_tail = flatten_tail(child_node);
  head->next = child_node;
  child_node->prev = head;
  if (next_node) {
    child_tail->next = next_node;
    next_node->prev = child_tail;
    return flatten_tail(next_node);
  }
  return child_tail;
}

class Solution {
public:
  Node *flatten(Node *head) {
    flatten_tail(head);
    return head;
  }
};
