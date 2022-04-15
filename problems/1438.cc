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

class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    auto get_push_op = [&nums](deque<int>& dq, auto cmp) {
      return [&dq, &nums, cmp](int i) {
        while (not empty(dq) and !cmp(nums[dq.back()], nums[i])) {
          dq.pop_back();
        }
        dq.push_back(i);
      };
    };
    deque<int> dq_incr;
    deque<int> dq_decr;
    auto push_incr = get_push_op(dq_incr, std::less<>{});
    auto push_decr = get_push_op(dq_decr, std::greater<>{});

    int const n = size(nums);
    int i{};
    int max_len = 0;
    for (int j{}; j < n; ++j) {
      push_incr(j);
      push_decr(j);
      while (nums[dq_decr.front()] - nums[dq_incr.front()] > limit) {
        if (dq_incr.front() == i) dq_incr.pop_front();
        if (dq_decr.front() == i) dq_decr.pop_front();
        ++i;
      }
      max_len = max(max_len, j - i + 1);
    }
    return max_len;
  }
};
