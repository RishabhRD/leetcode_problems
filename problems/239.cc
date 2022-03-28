#include <list>
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

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int const n = size(nums);
    list<int> dq;
    auto push = [&](int idx) {
      while (not empty(dq) and nums[dq.back()] <= nums[idx]) { dq.pop_back(); }
      dq.push_back(idx);
    };
    for (int i = 0; i < k; i++) { push(i); }
    vector<int> res({ nums[dq.front()] });
    for (int i = k; i < n; i++) {
      if (dq.front() <= i - k) { dq.pop_front(); }
      push(i);
      res.push_back(nums[dq.front()]);
    }
    return res;
  }
};
