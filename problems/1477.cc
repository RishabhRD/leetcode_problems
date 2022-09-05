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

auto make_suffix_min_len_target_sum(std::vector<int> const& arr, int target) {
  auto const n = std::size(arr);
  int cur_sum = 0;
  int low = n - 1;
  int min_len = n + 1;
  std::vector<int> ans(n, min_len);
  for (int high = n - 1; high >= 0; --high) {
    cur_sum += arr[high];

    while (cur_sum > target) {
      cur_sum -= arr[low];
      --low;
    }

    if (cur_sum == target) {
      min_len = std::min(min_len, low - high + 1);
      ans[high] = min_len;
    } else {
      ans[high] = min_len;
    }
  }
  return ans;
}

class Solution {
 public:
  int minSumOfLengths(std::vector<int>& arr, int target) {
    auto const n = std::size(arr);
    auto const suffix_min_len = make_suffix_min_len_target_sum(arr, target);

    int low = 0;
    int cur_sum = 0;
    int min_len = n + 1;
    int ans = n + 1;
    for (int high = 0; high < n - 1; ++high) {
      cur_sum += arr[high];

      while (cur_sum > target) {
        cur_sum -= arr[low];
        ++low;
      }
      if (cur_sum == target) {
        min_len = std::min(min_len, high - low + 1);
        ans = std::min(ans, min_len + suffix_min_len[high + 1]);
      }
    }
    if (ans == n + 1) return -1;
    return ans;
  }
};
