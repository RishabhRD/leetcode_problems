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

int total_rectangle(std::vector<int> const& nums) {
  auto const n = std::size(nums);
  std::vector<int> left(n);
  std::vector<int> right(n);
  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (not std::empty(st) and nums[st.top()] >= nums[i]) {
      st.pop();
    }
    if (st.empty())
      left[i] = i;
    else
      left[i] = i - st.top() - 1;
    st.push(i);
  }

  st = std::stack<int>{};
  for (int i = n - 1; i >= 0; --i) {
    while (not std::empty(st) and nums[st.top()] > nums[i]) {
      st.pop();
    }
    if (st.empty())
      right[i] = n - i - 1;
    else
      right[i] = st.top() - i - 1;
    st.push(i);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto const k = left[i] + right[i] + 1;
    ans += k * nums[i];
  }
  for (auto l : left) std::cout << l << ' ';
  std::cout << std::endl;
  for (auto l : right) std::cout << l << ' ';
  std::cout << std::endl;
  std::cout << ans << std::endl;
  return ans;
}

class Solution {
 public:
  int numSubmat(std::vector<std::vector<int>>& matrix) {
    auto const m = std::size(matrix);
    auto const n = std::size(matrix[0]);
    std::vector num_one(m, std::vector(n, 0));
    num_one[0] = matrix[0];

    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 1) num_one[i][j] = 1 + num_one[i - 1][j];
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cout << num_one[i][j] << ' ';
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
    return std::accumulate(
        std::begin(num_one), std::end(num_one), 0,
        [](auto prev, auto const& cur) { return prev + total_rectangle(cur); });
  }
};
