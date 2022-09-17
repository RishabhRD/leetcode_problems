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

class Solution {
 public:
  std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
    std::multiset<int> st{std::begin(nums), std::begin(nums) + k};
    auto mid = std::next(std::begin(st), (k - 1) / 2);
    std::vector<double> res;
    for (int high = k;; ++high) {
      double sum = 0;
      sum += *mid;
      if (k % 2 == 0) {
        sum += *(next(mid));
        res.push_back(sum / 2);
      } else {
        res.push_back(sum);
      }
      if (high == std::size(nums)) break;

      st.insert(nums[high]);
      if (nums[high] < *mid) --mid;
      if (nums[high - k] <= *mid) ++mid;
      st.erase(st.find(nums[high - k]));
    }
    return res;
  }
};
