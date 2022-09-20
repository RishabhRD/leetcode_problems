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

auto add(std::vector<int> const& vec) { return vec[0] + vec[1]; }

auto diff(std::vector<int> const& vec) { return vec[1] - vec[0]; }

class Solution {
 public:
  int findMaxValueOfEquation(std::vector<std::vector<int>>& points, int k) {
    std::deque<int> dq;
    int const n = std::size(points);
    int ans = INT32_MIN;

    int low = 0;
    for (int i = 0; i < n; ++i) {
      while (points[i][0] - points[low][0] > k) {
        if (not dq.empty() and dq.front() == low) dq.pop_front();
        ++low;
      }
      if (!dq.empty())
        ans = std::max(ans, diff(points[dq.front()]) + add(points[i]));
      while (not std::empty(dq) and diff(points[dq.back()]) < diff(points[i])) {
        dq.pop_back();
      }
      dq.push_back(i);
    }
    return ans;
  }
};
