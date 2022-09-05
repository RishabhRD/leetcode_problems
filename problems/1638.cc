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

template <typename Callback>
auto for_each_adj(std::string_view str, Callback const& callback) {
  std::string s{str};
  for (auto& c : s) {
    auto const old = c;
    for (char cur = 'a'; cur <= 'z'; ++cur) {
      if (cur != old) {
        c = cur;
        callback(s);
      }
    }
    c = old;
  }
}

class Solution {
 public:
  int countSubstrings(std::string const s_str, std::string const t_str) {
    std::unordered_map<std::string_view, int> mp;

    std::string_view const s = s_str;
    std::string_view const t = t_str;

    auto const m = std::size(s);
    auto const n = std::size(t);

    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        ++mp[t.substr(i, j - i + 1)];
      }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = i; j < m; ++j) {
        auto const cur_str = s.substr(i, j - i + 1);
        for_each_adj(cur_str, [&](std::string_view str) {
          if (mp.find(str) != mp.end()) {
            ans += mp[str];
          }
        });
      }
    }
    return ans;
  }
};
