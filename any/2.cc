#include <optional>
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

int to_carry(int num) { return num / 10; }

int to_add_digit(int num) { return num % 10; }

auto sum_digits_with_carry(ListNode const *n1, ListNode const *n2, int carry) {
  int sum = 0;
  if (n1) sum += n1->val;
  if (n2) sum += n2->val;
  sum += carry;
  return pair{ new ListNode(to_add_digit(sum)), to_carry(sum) };
}

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *sum_nodes_head = new ListNode;
    auto sum_nodes = sum_nodes_head;
    auto add_list_digit = [&] {
      auto [digit_node, new_carry] = sum_digits_with_carry(l1, l2, carry);
      carry = new_carry;
      sum_nodes->next = digit_node;
      sum_nodes = digit_node;
    };
    while (l1 and l2) {
      add_list_digit();
      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1) {
      add_list_digit();
      l1 = l1->next;
    }
    while (l2) {
      add_list_digit();
      l2 = l2->next;
    }
    if (carry) { add_list_digit(); }
    return sum_nodes_head->next;
  }
};
