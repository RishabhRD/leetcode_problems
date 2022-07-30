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
  vector<int> getAverages(vector<int>& nums, int k) {
    auto const n = std::size(nums);
    std::vector<int> averages(n, -1);
    auto const win_size = 2 * k + 1;
    if (win_size > n) return averages;
    auto cur_value =
        std::accumulate(std::cbegin(nums), std::cbegin(nums) + win_size, 0ll);
    averages[k] = cur_value / win_size;
    for (int i = k + 1; i + k < n; ++i) {
      cur_value -= nums[i - k - 1];
      cur_value += nums[i + k];
      averages[i] = cur_value / win_size;
    }
    return averages;
  }
};
