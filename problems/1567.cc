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

template <typename Iter, typename Callback>
auto split_with_zero(Iter begin, Iter end, Callback callback) {
  auto first = begin;
  auto last = std::find(begin, end, 0);
  callback(first, last);
  while (last != end) {
    ++last;
    first = last;
    last = std::find(first, end, 0);
    callback(first, last);
  }
}

bool is_neg(int num) { return num < 0; }

template <typename Iter>
auto count_max_positive(Iter begin, Iter end) {
  auto const num_neg = std::count_if(begin, end, is_neg);
  if (num_neg % 2 == 0) return std::distance(begin, end);
  auto const left_neg = std::find_if(begin, end, is_neg);
  auto const left_left_dist = left_neg - begin;
  auto const left_right_dist = end - left_neg - 1;

  auto const rev_begin = std::reverse_iterator{end};
  auto const rev_end = std::reverse_iterator{begin};
  auto const right_neg = std::find_if(rev_begin, rev_end, is_neg);

  auto const right_right = right_neg - rev_begin;
  auto const right_left = rev_end - right_neg - 1;

  return std::max({left_left_dist, left_right_dist, right_right, right_left});
}

class Solution {
 public:
  int getMaxLen(std::vector<int>& nums) {
    auto ans = 0;
    split_with_zero(
        std::cbegin(nums), std::cend(nums), [&](auto begin, auto end) {
          ans = std::max(ans, static_cast<int>(count_max_positive(begin, end)));
        });
    return ans;
  }
};
