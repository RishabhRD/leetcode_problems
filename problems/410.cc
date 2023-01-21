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

using ll = long long;

template <typename Predicate>
ll bs(ll low, ll high, Predicate&& predicate) {
  if (low >= high) return low;
  auto const mid = low + (high - low) / 2;
  if (predicate(mid)) {
    return bs(mid + 1, high, predicate);
  } else {
    return bs(low, mid, predicate);
  }
}

class Solution {
 public:
  int splitArray(std::vector<int>& nums, int k) {
    auto const max = *std::max_element(std::begin(nums), std::end(nums));
    auto const sum = std::reduce(std::begin(nums), std::end(nums), 0);
    auto count = [&](ll s) {
      ll cur_sum = 0;
      ll count = 0;
      for (auto n : nums) {
        cur_sum += n;
        if (cur_sum > s) {
          ++count;
          cur_sum = n;
        }
      }
      return count + 1;
    };
    return bs(max, sum + 1, [&](ll s) { return count(s) > k; });
  }
};
