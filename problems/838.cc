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

constexpr int inf = INT32_MAX;

auto increment_with_inf_check(int n) {
  if (n == inf) {
    return n;
  }
  return n + 1;
}

auto inf_for_1_zero_for_2_else_increment(char first, char second) {
  return [first, second](auto init, auto cur) {
    if (cur == first)
      return inf;
    else if (cur == second)
      return 0;
    else
      return increment_with_inf_check(init);
  };
}

auto make_left_rights(std::string_view dominoes) {
  auto const begin = std::cbegin(dominoes);
  auto const end = std::cend(dominoes);
  std::vector<int> left_right(dominoes.size());
  auto const to_write_itr = std::begin(left_right);
  std::inclusive_scan(begin, end, to_write_itr,
                      inf_for_1_zero_for_2_else_increment('L', 'R'), inf);
  return left_right;
}

auto make_right_lefts(std::string_view dominoes) {
  auto const begin = std::crbegin(dominoes);
  auto const end = std::crend(dominoes);
  std::vector<int> right_lefts(dominoes.size());
  auto const to_write_itr = std::rbegin(right_lefts);
  std::inclusive_scan(begin, end, to_write_itr,
                      inf_for_1_zero_for_2_else_increment('R', 'L'), inf);
  return right_lefts;
}

class Solution {
 public:
  std::string pushDominoes(std::string dominoes) {
    auto const n = std::size(dominoes);
    auto const left_right_dists = make_left_rights(dominoes);
    auto const right_left_dists = make_right_lefts(dominoes);
    for (int i = 0; i < n; ++i) {
      if (dominoes[i] == '.') {
        if (left_right_dists[i] > right_left_dists[i]) {
          dominoes[i] = 'L';
        } else if (left_right_dists[i] < right_left_dists[i]) {
          dominoes[i] = 'R';
        }
      }
    }
    return dominoes;
  }
};
