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

void dfs(ll i, ll n, std::vector<std::pair<ll, ll>>& cur,
         std::vector<std::vector<std::string>>& res) {
  if (i == n) {
    std::vector<std::string> ans;
    for (auto [_, j] : cur) {
      std::string s;
      for (ll k = 0; k < n; ++k) {
        if (k != j)
          s += '.';
        else
          s += 'Q';
      }
      ans.push_back(s);
    }
    res.push_back(ans);
    return;
  }

  for (ll j = 0; j < n; ++j) {
    auto const is_good = [&] {
      for (auto [x, y] : cur) {
        auto const diff = i - x;
        auto const diff1 = std::abs(y - j);
        if (diff == diff1) {
          return false;
        }
        if (y == j) return false;
      }
      return true;
    }();
    if (is_good) {
      cur.push_back({i, j});
      dfs(i + 1, n, cur, res);
      cur.pop_back();
    }
  }
}

class Solution {
 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::pair<ll, ll>> cur;
    dfs(0, n, cur, res);
    return res;
  }
};
