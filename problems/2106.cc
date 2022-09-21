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

auto create_left_vec(std::vector<std::vector<int>> const& fruits, int startPos,
                     int k) {
  std::vector<std::pair<int, int>> res;
  for (auto const& fruit : fruits) {
    if (fruit[0] < startPos and startPos - fruit[0] <= k) {
      res.push_back({startPos - fruit[0], fruit[1]});
    }
  }
  std::reverse(std::begin(res), std::end(res));
  return res;
}

auto create_right_vec(std::vector<std::vector<int>> const& fruits, int startPos,
                      int k) {
  std::vector<std::pair<int, int>> res;
  for (auto const& fruit : fruits) {
    if (fruit[0] >= startPos and fruit[0] - startPos <= k) {
      res.push_back({fruit[0] - startPos, fruit[1]});
    }
  }
  return res;
}

auto create_fruit_partial_sum(std::vector<std::pair<int, int>> const& fruits) {
  std::vector<int> res;
  int sum = 0;
  for (auto [pos, num] : fruits) {
    sum += num;
    res.push_back(sum);
  }
  return res;
}

auto max_fruits(std::vector<std::pair<int, int>> const& left_vec,
                std::vector<int> const& left_prefix_sum,
                std::vector<std::pair<int, int>> const& right_vec,
                std::vector<int> const& right_prefix_sum, int k) {
  int ans = 0;
  if (right_prefix_sum.size() != 0) ans = right_prefix_sum.back();
  int right = std::size(right_prefix_sum) - 1;
  for (int left = 0; left < std::size(left_vec); ++left) {
    auto const left_pos = left_vec[left].first;
    auto const left_num = left_prefix_sum[left];
    auto const remaining = k - 2 * left_pos;
    while (right >= 0 and right_vec[right].first > remaining) {
      --right;
    }
    int right_num = 0;
    if (right >= 0) {
      right_num = right_prefix_sum[right];
    }
    ans = std::max(ans, left_num + right_num);
  }
  return ans;
}

class Solution {
 public:
  int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos,
                     int k) {
    auto const right_vec = create_right_vec(fruits, startPos, k);
    auto const right_prefix_sum = create_fruit_partial_sum(right_vec);
    auto const left_vec = create_left_vec(fruits, startPos, k);
    auto const left_prefix_sum = create_fruit_partial_sum(left_vec);
    return std::max(
        max_fruits(left_vec, left_prefix_sum, right_vec, right_prefix_sum, k),
        max_fruits(right_vec, right_prefix_sum, left_vec, left_prefix_sum, k));
  }
};
