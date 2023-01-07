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
ll constexpr mod = 1e9 + 7;

class Solution {
 public:
  int sumSubarrayMins(std::vector<int> &arr) {
    auto const n = std::size(arr);
    std::vector next_smaller_idx(n, -1);
    {
      std::stack<int> st;
      for (int i = n - 1; i >= 0; --i) {
        while (st.size() && arr[st.top()] > arr[i]) {
          st.pop();
        }
        if (st.empty()) {
          next_smaller_idx[i] = -1;
        } else {
          next_smaller_idx[i] = st.top();
        }
        st.push(i);
      }
    }
    std::vector prev_smaller_idx(n, -1);
    {
      std::stack<int> st;
      for (int i = 0; i < n; ++i) {
        while (st.size() && arr[st.top()] >= arr[i]) {
          st.pop();
        }
        if (st.empty()) {
          prev_smaller_idx[i] = -1;
        } else {
          prev_smaller_idx[i] = st.top();
        }
        st.push(i);
      }
    }
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
      ll num_smaller_left = 0;
      ll num_smaller_right = 0;
      if (next_smaller_idx[i] == -1) {
        num_smaller_right = n - i;
      } else {
        num_smaller_right = next_smaller_idx[i] - i;
      }
      if (prev_smaller_idx[i] == -1) {
        num_smaller_left = i + 1;
      } else {
        num_smaller_left = i - prev_smaller_idx[i];
      }
      sum = (sum +
             (((arr[i] * num_smaller_left) % mod) * num_smaller_right) % mod) %
            mod;
    }
    return sum;
  }
};
