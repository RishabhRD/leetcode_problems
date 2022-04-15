#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
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
  vector<int> maxSlidingWindow(vector<int> const &nums, int k) {
    deque<int> dq;
    auto push = [&](auto i) {
      while (not empty(dq) and nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
    };

    int const n = size(nums);
    vector<int> res;

    for (int i = 0; i < k; ++i) push(i);
    for (int i = k; i < n; ++i) {
      res.push_back(nums[dq.front()]);
      if (dq.front() <= i - k) {
        dq.pop_front();
      }
      push(i);
    }
    res.push_back(nums[dq.front()]);
    return res;
  }
};
