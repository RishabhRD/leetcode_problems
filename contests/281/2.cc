#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    auto dummy_head = new ListNode;
    auto dummy = dummy_head;
    int cur_sum = 0;
    head = head->next;
    while (head) {
      if (head->val == 0) {
        dummy->next = new ListNode(cur_sum);
        cur_sum = 0;
        dummy = dummy->next;
      } else {
        cur_sum += head->val;
      }
      if (head) head = head->next;
    }
    return dummy_head->next;
  }
};
