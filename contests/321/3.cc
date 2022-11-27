#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

using ll = long long;

auto get_vector(ListNode* head) {
  std::vector<int> res;
  while (head) {
    res.push_back(head->val);
    head = head->next;
  }
  return res;
}

auto make_to_remove(std::vector<int> const& nums) {
  auto const n = std::size(nums);
  std::set<int> st;
  std::unordered_set<int> to_remove;
  for (int i = n - 1; i >= 0; --i) {
    if (st.upper_bound(nums[i]) != st.end()) {
      to_remove.insert(i);
    }
    st.insert(nums[i]);
  }
  return to_remove;
}

class Solution {
 public:
  ListNode* removeNodes(ListNode* head) {
    auto const nums = get_vector(head);
    auto const n = std::size(nums);
    auto const to_remove = make_to_remove(nums);
    ListNode* dummy_head = new ListNode();
    ListNode* dummy_cur = dummy_head;
    int cur = 0;
    while (head) {
      if (!to_remove.count(cur)) {
        dummy_cur->next = head;
        dummy_cur = dummy_cur->next;
      }
      head = head->next;
      ++cur;
    }
    return dummy_head->next;
  }
};
