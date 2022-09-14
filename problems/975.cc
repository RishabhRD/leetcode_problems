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

template <typename Comp>
auto next_for_comparision(std::vector<int> const& nums, Comp comp) {
  auto const n = std::size(nums);
  std::vector<int> ans(n);
  auto cmp = [&](auto a, auto b) {
    if (nums[a] == nums[b]) return a < b;
    return comp(nums[a], nums[b]);
  };
  std::set<int, decltype(cmp)> st(cmp);
  st.insert(n - 1);
  for (int i = n - 2; i >= 0; i--) {
    auto itr = st.lower_bound(i);
    if (itr == st.end()) {
      ans[i] = -1;
    } else {
      ans[i] = *itr;
    }
    st.insert(i);
  }
  ans[n - 1] = -1;
  return ans;
}

bool dfs(std::vector<int> const& next_greater,
         std::vector<int> const& next_smaller, int i, bool greater_turn,
         std::vector<std::optional<bool>>& greater_dp,
         std::vector<std::optional<bool>>& smaller_dp) {
  if (greater_turn) {
    if (greater_dp[i].has_value()) return greater_dp[i].value();
    if (next_greater[i] == -1)
      greater_dp[i] = false;
    else
      greater_dp[i] = dfs(next_greater, next_smaller, next_greater[i], false,
                          greater_dp, smaller_dp);
    return greater_dp[i].value();
  } else {
    if (smaller_dp[i].has_value()) return smaller_dp[i].value();
    if (next_smaller[i] == -1)
      smaller_dp[i] = false;
    else
      smaller_dp[i] = dfs(next_greater, next_smaller, next_smaller[i], true,
                          greater_dp, smaller_dp);
    return smaller_dp[i].value();
  }
}

class Solution {
 public:
  int oddEvenJumps(std::vector<int> const& arr) {
    auto const next_greater = next_for_comparision(arr, std::less{});
    auto const next_smaller = next_for_comparision(arr, std::greater{});
    std::vector greater(std::size(arr), std::optional<bool>{});
    std::vector smaller(std::size(arr), std::optional<bool>{});
    greater[std::size(arr) - 1] = true;
    smaller[std::size(arr) - 1] = true;
    int sum = 0;
    for (int i = 0; i < std::size(arr); ++i) {
      if (dfs(next_greater, next_smaller, i, true, greater, smaller)) ++sum;
    }
    return sum;
  }
};
