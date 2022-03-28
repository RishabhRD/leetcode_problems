#include <queue>
#include <unordered_set>
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

auto size(ListNode *head) {
  size_t cnt = 0;
  while (head) {
    cnt++;
    head = head->next;
  }
  return cnt;
}

ListNode *reverse_atmost_k(ListNode *head, int k) {
  if (size(head) < k) return head;
  auto head_cpy = head;
  ListNode *new_head = nullptr;
  int cur = 1;
  while (head) {
    if (cur > k) break;
    auto next = head->next;
    head->next = new_head;
    new_head = head;
    head = next;
    cur++;
  }
  head_cpy->next = reverse_atmost_k(head, k);
  return new_head;
}

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    return reverse_atmost_k(head, k);
  }
};
