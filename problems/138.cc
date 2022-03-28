#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
    while (cur) {
      auto next_node = cur->next;
      auto new_node = new Node(cur->val);
      new_node->next = next_node;
      new_node->random = cur->random;
      cur->next = new_node;
      cur = next_node;
    }
    cur = head;
    while (cur) {
      cur->next->random = cur->random ? cur->random->next : nullptr;
      cur = cur->next->next;
    }
    Node *res_head = new Node(0);
    Node *res = res_head;
    cur = head;
    while (cur) {
      auto next_node = cur->next->next;
      auto copy_node = cur->next;
      res->next = copy_node;
      res = copy_node;
      cur->next = next_node;
      copy_node->next = next_node ? next_node->next : nullptr;
      cur = next_node;
    }
    return res_head->next;
  }
};
