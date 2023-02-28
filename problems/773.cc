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

auto to_vec(ll n) {
  std::vector<ll> digits;
  while (n) {
    digits.push_back(n % 10);
    n /= 10;
  }
  if (digits.size() == 5) digits.push_back(0);
  std::reverse(std::begin(digits), std::end(digits));
  return digits;
}

auto get_number(std::vector<ll>& nums, ll i, ll j) {
  std::swap(nums[i], nums[j]);
  ll num = 0;
  for (auto n : nums) {
    num = num * 10 + n;
  }
  std::swap(nums[i], nums[j]);
  return num;
}

auto get_neighbors(ll n) {
  auto digits = to_vec(n);
  auto const idx =
      std::find(std::begin(digits), std::end(digits), 0) - std::begin(digits);
  std::vector<ll> res;
  if (idx == 0) {
    res.push_back(get_number(digits, 0, 1));
    res.push_back(get_number(digits, 0, 3));
  } else if (idx == 1) {
    res.push_back(get_number(digits, 1, 0));
    res.push_back(get_number(digits, 1, 2));
    res.push_back(get_number(digits, 1, 4));
  } else if (idx == 2) {
    res.push_back(get_number(digits, 2, 1));
    res.push_back(get_number(digits, 2, 5));
  } else if (idx == 3) {
    res.push_back(get_number(digits, 3, 0));
    res.push_back(get_number(digits, 3, 4));
  } else if (idx == 4) {
    res.push_back(get_number(digits, 4, 1));
    res.push_back(get_number(digits, 4, 3));
    res.push_back(get_number(digits, 4, 5));
  } else if (idx == 5) {
    res.push_back(get_number(digits, 5, 2));
    res.push_back(get_number(digits, 5, 4));
  }
  return res;
}

class Solution {
 public:
  int slidingPuzzle(std::vector<std::vector<int>>& board) {
    ll init = 0;
    for (ll i = 0; i < 2; ++i) {
      for (ll j = 0; j < 3; ++j) {
        init = init * 10 + board[i][j];
      }
    }
    std::queue<ll> q;
    std::unordered_set<ll> visited;
    q.push(init);
    visited.insert(init);
    ll cur_level = 0;
    while (!q.empty()) {
      auto sz = q.size();
      while (sz--) {
        auto const top = q.front();
        if (top == 123450) return cur_level;
        q.pop();
        for (auto n : get_neighbors(top)) {
          if (!visited.count(n)) {
            q.push(n);
            visited.insert(n);
          }
        }
      }
      ++cur_level;
    }
    return -1;
  }
};
