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

constexpr long long mod = 1e9 + 7;

template <typename Prev, typename Cur>
auto plus_with_mod(Prev prev, Cur cur) {
  return (prev % mod + cur % mod) % mod;
}

template <typename Iter>
auto calc_max_sum_from_starting(Iter begin, Iter end) {
  long long max_sum = INT32_MIN;
  long long cur_sum = 0;
  for_each(begin, end, [&](auto ele) {
    cur_sum = plus_with_mod(cur_sum, ele);
    max_sum = std::max(cur_sum, max_sum);
  });
  return max_sum;
}

long long calc_max_suffix_sum(std::vector<int> const& arr) {
  return calc_max_sum_from_starting(std::crbegin(arr), std::crend(arr));
}

long long calc_max_prefix_sum(std::vector<int> const& arr) {
  return calc_max_sum_from_starting(std::cbegin(arr), std::cend(arr));
}

long long calc_kadane_max(std::vector<int> const& arr) {
  long long max_sum = INT32_MIN;
  long long cur_sum = 0;
  for (long long ele : arr) {
    cur_sum = std::max((cur_sum + ele) % mod, ele);
    max_sum = std::max(max_sum, cur_sum);
  }
  return max_sum;
}

class Solution {
 public:
  int kConcatenationMaxSum(std::vector<int>& arr, int k) {
    long long const kadane_max = calc_kadane_max(arr);
    if (k == 1) return kadane_max;
    long long const total = std::reduce(std::cbegin(arr), std::cend(arr), 0);
    long long const max_prefix_sum = calc_max_prefix_sum(arr);
    long long const max_suffix_sum = calc_max_suffix_sum(arr);
    if (total > 0) {
      auto const kadane_ans = kadane_max % mod;
      auto const k_2_array_sum = ((k - 2) * total) % mod;
      auto const other_ans = plus_with_mod(
          plus_with_mod(k_2_array_sum, max_prefix_sum), max_suffix_sum);
      return std::max(kadane_ans, other_ans);
    } else {
      return std::max(
          {kadane_max, (max_prefix_sum + max_suffix_sum) % mod, 0ll});
    }
  }
};
