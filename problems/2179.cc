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

template <typename T, typename GroupFunc>
class segment_tree {
  GroupFunc func;
  ll n;
  std::vector<T> arr;

 public:
  segment_tree(std::vector<T> const &arr, GroupFunc func)
      : func(std::move(func)), n(std::size(arr)), arr(n * 4) {
    build(1, 0, n - 1, arr);
  }

  T query(ll tl, ll tr) { return query(1, 0, n - 1, tl, tr); }

  void update(ll i, T const &val) {
    update(i, [val](auto e) { return val; });
  }

  template <typename F>
  void update(ll i, F &&f) {
    update(1, 0, n - 1, i, f);
  }

 private:
  void build(ll i, ll l, ll r, std::vector<T> const &vec) {
    if (l == r) {
      arr[i] = vec[l];
    } else {
      auto const m = l + ((r - l) / 2);
      build(2 * i, l, m, vec);
      build(2 * i + 1, m + 1, r, vec);
      arr[i] = func(arr[2 * i], arr[2 * i + 1]);
    }
  }

  T query(ll i, ll l, ll r, ll tl, ll tr) {
    if (l == tl && r == tr) return arr[i];
    auto const m = l + ((r - l) / 2);
    if (tl >= l and tr <= m) {
      return query(2 * i, l, m, tl, tr);
    } else if (tl >= (m + 1) and tr <= r) {
      return query(2 * i + 1, m + 1, r, tl, tr);
    } else {
      auto const left = query(2 * i, l, m, tl, m);
      auto const right = query(2 * i + 1, m + 1, r, m + 1, tr);
      return func(left, right);
    }
  }

  template <typename F>
  void update(ll i, ll l, ll r, ll idx, F &&f) {
    if (l == r) {
      arr[i] = f(arr[i]);
      return;
    }
    auto const m = l + ((r - l) / 2);
    if (idx <= m) {
      update(2 * i, l, m, idx, f);
    } else {
      update(2 * i + 1, m + 1, r, idx, f);
    }
    arr[i] = func(arr[2 * i], arr[2 * i + 1]);
  }
};

template <typename T, typename GroupFunc>
segment_tree(std::vector<T> const &, GroupFunc) -> segment_tree<T, GroupFunc>;

auto calc_left(std::vector<int> const &nums) {
  ll const n = nums.size();
  segment_tree stree(std::vector(n, 0), std::plus<>{});
  std::vector<ll> left(n);
  for (ll i = 0; i < n; ++i) {
    auto const num_left = nums[i] == 0 ? 0 : stree.query(0, nums[i] - 1);
    stree.update(nums[i], [](auto n) { return n + 1; });
    left[nums[i]] = num_left;
  }
  return left;
}

auto calc_right(std::vector<int> const &nums) {
  ll const n = nums.size();
  segment_tree stree(std::vector(n, 0), std::plus<>{});
  std::vector<ll> right(n);
  for (ll i = n - 1; i >= 0; --i) {
    auto const num_right =
        nums[i] == n - 1 ? 0 : stree.query(nums[i] + 1, n - 1);
    stree.update(nums[i], [](auto n) { return n + 1; });
    right[nums[i]] = num_right;
  }
  return right;
}

class Solution {
 public:
  long long goodTriplets(std::vector<int> &nums1, std::vector<int> &nums2) {
    ll const n = nums1.size();
    std::vector idx(n, 0);
    for (ll i = 0; i < n; ++i) {
      idx[nums1[i]] = i;
    }
    for (auto &n : nums2) {
      n = idx[n];
    }
    auto const left = calc_left(nums2);
    auto const right = calc_right(nums2);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
      sum += left[i] * right[i];
    }
    return sum;
  }
};
