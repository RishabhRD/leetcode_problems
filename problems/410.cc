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
    auto is_possible = [&](auto max) {
      ll cur_k = k - 1;
      ll cur_sum = 0;
      for (auto n : nums) {
        cur_sum += n;
        if (cur_sum > max) {
          --cur_k;
          cur_sum = n;
        }
      }
      return cur_k < 0;
    };
    auto max = bs(0, 1e9 + 1, is_possible);
    ll cur_sum = 0;
    ll max_sum = cur_sum;
    for (auto n : nums) {
      cur_sum += n;
      if (cur_sum > max) {
        cur_sum = n;
      }
      max_sum = std::max(cur_sum, max_sum);
    }
    return max_sum;
  }
};
