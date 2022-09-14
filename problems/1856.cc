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

class Solution {
 public:
  int maxSumMinProduct(std::vector<int> const& nums) {
    constexpr int mod = 1e9 + 7;
    auto const n = std::size(nums);
    using ll = unsigned long long;
    std::vector<ll> prefix_sum(n + 1);
    std::inclusive_scan(std::begin(nums), std::end(nums),
                        std::next(std::begin(prefix_sum)), std::plus{}, ll(0));
    auto const sum_of = [&prefix_sum](auto i, auto j) -> long long {
      return prefix_sum[j + 1] - prefix_sum[i];
    };

    std::vector<int> left(n);
    std::vector<int> right(n);

    std::stack<int> st;
    for (int i = 0; i < n; ++i) {
      while (not std::empty(st) and nums[st.top()] >= nums[i]) {
        st.pop();
      }
      if (st.empty())
        left[i] = 0;
      else
        left[i] = st.top() + 1;
      st.push(i);
    }

    st = std::stack<int>{};
    for (int i = n - 1; i >= 0; --i) {
      while (not std::empty(st) and nums[st.top()] >= nums[i]) {
        st.pop();
      }
      if (st.empty())
        right[i] = n - 1;
      else
        right[i] = st.top() - 1;
      st.push(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = std::max(ans, nums[i] * sum_of(left[i], right[i]));
    }
    return ans % mod;
  }
};
