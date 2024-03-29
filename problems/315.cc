#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

// NOTE: There are 2 solutions here
// 1. Segment tree
// 2. Merge Sort

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

class MySolution {
 public:
  std::vector<int> countSmaller(std::vector<int> &nums) {
    for (auto &n : nums) n += 1e4;
    segment_tree stree{std::vector(1e5 + 1, 0ll), std::plus<>{}};
    ll const n = nums.size();
    std::vector<int> ans(n);
    for (ll i = n - 1; i >= 0; --i) {
      ans[i] = nums[i] == 0 ? 0 : stree.query(0, nums[i] - 1);
      stree.update(nums[i], [](auto n) { return n + 1; });
    }
    return ans;
  }
};

void merge(ll low, ll mid, ll high, std::vector<std::pair<int, int>> &nums,
           std::vector<int> &count) {
  ll j = mid + 1;
  for (ll i = low; i <= mid; ++i) {
    while (j <= high && nums[j].first < nums[i].first) {
      ++j;
    }
    count[nums[i].second] += j - mid - 1;
  }
  std::sort(std::begin(nums) + low, std::begin(nums) + high + 1);
}

void ms(ll low, ll high, std::vector<std::pair<int, int>> &nums,
        std::vector<int> &count) {
  if (low == high) {
    return;
  }
  auto const mid = (low + (high - low) / 2);
  ms(low, mid, nums, count);
  ms(mid + 1, high, nums, count);
  merge(low, mid, high, nums, count);
}

class Solution {
 public:
  std::vector<int> countSmaller(std::vector<int> &nums) {
    ll const n = nums.size();
    std::vector<std::pair<int, int>> zipped;
    for (ll i = 0; i < n; ++i) {
      zipped.push_back({nums[i], i});
    }
    std::vector<int> count(n);
    ms(0, n - 1, zipped, count);
    return count;
  }
};
