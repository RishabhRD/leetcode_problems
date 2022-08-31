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

template <typename InIter, typename OutIter>
auto monotonic_stack(InIter const low, InIter const high, OutIter out) {
  std::stack<InIter> st;
  for (auto itr = low; itr != high; ++itr) {
    auto const ele = *itr;
    while (not std::empty(st) and *st.top() >= ele) {
      st.pop();
    }
    if (st.empty())
      *out = high;
    else
      *out = st.top();
    st.push(itr);
    ++out;
  }
}

auto make_prev_smaller(std::vector<int> const& arr) {
  auto const n = std::size(arr);
  std::vector out(n, std::cend(arr));
  monotonic_stack(std::cbegin(arr), std::cend(arr), std::begin(out));
  return out;
}

auto make_next_smaller(std::vector<int> const& arr) {
  auto const n = std::size(arr);
  std::vector out(n, std::crend(arr));
  monotonic_stack(std::crbegin(arr), std::crend(arr), std::rbegin(out));
  return out;
}

class Solution {
 public:
  int sumSubarrayMins(std::vector<int>& arr) {
    auto const n = std::size(arr);
    std::stack<int> st;
    std::vector<int> prev_smaller(n);
    for (int i = 0; i < n; ++i) {
      while (!st.empty() and arr[st.top()] >= arr[i]) {
        st.pop();
      }
      if (st.empty())
        prev_smaller[i] = -1;
      else
        prev_smaller[i] = st.top();
      st.push(i);
    }
    st = std::stack<int>{};
    std::vector<int> next_smaller(n);
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() and arr[st.top()] > arr[i]) {
        st.pop();
      }
      if (st.empty())
        next_smaller[i] = n;
      else
        next_smaller[i] = st.top();
      st.push(i);
    }

    constexpr static int mod = 1e9 + 7;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      long long const prev_smaller_dist = i - prev_smaller[i];
      long long const next_smaller_dist = next_smaller[i] - i;
      sum =
          (sum + (prev_smaller_dist * next_smaller_dist * arr[i]) % mod) % mod;
    }
    return sum;
  }
};
