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

int get(std::vector<int> const& nums, int i) {
  if (i < 0) return 0;
  if (i >= std::size(nums)) return 0;
  return nums[i];
}

template <typename Iter, typename Out>
auto const make_parity_sum(Iter begin, Iter end, Out out) {
  bool turn = false;
  int even_sum = 0;
  int odd_sum = 0;
  while (begin != end) {
    if (turn) {
      even_sum += *begin;
      *out = even_sum;
    } else {
      odd_sum += *begin;
      *out = odd_sum;
    }
    turn = !turn;
    ++out;
    ++begin;
  }
}

auto const make_right_parity_sum(std::vector<int> const& nums) {
  std::vector ans = nums;
  make_parity_sum(std::crbegin(nums), std::crend(nums), std::rbegin(ans));
  return ans;
}

auto const make_left_parity_sum(std::vector<int> const& nums) {
  std::vector ans = nums;
  make_parity_sum(std::cbegin(nums), std::cend(nums), std::begin(ans));
  return ans;
}

class Solution {
 public:
  int waysToMakeFair(std::vector<int>& nums) {
    auto const n = std::size(nums);
    auto const left_parity_sum = make_left_parity_sum(nums);
    auto const right_parity_sum = make_right_parity_sum(nums);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (get(left_parity_sum, i - 2) + get(right_parity_sum, i + 1) ==
          get(left_parity_sum, i - 1) + get(right_parity_sum, i + 2)) {
        ++ans;
      }
    }
    return ans;
  }
};
