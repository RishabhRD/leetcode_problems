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
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void deleteNode(ListNode *node) {
    auto cur = node;
    ListNode *prev = nullptr;
    while (cur and cur->next) {
      prev = cur;
      swap(cur->val, cur->next->val);
      cur = cur->next;
    }
    prev->next = nullptr;
  }
};
