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
  ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
    auto l1 = head1;
    auto l2 = head2;
    while (l1 != l2) {
      l1 = l1 ? l1->next : head2;
      l2 = l2 ? l2->next : head1;
    }
    return l1;
  }
};
