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

auto precompute(std::string_view s) {
  ll const n = s.size();
  std::unordered_map<ll, std::pair<ll, ll>> mp;
  for (ll i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (mp.find(0) == mp.end()) {
        mp[0] = {i, i};
      }
      continue;
    }
    ll cur_val = 0;
    ll const max = std::min(i + 32, n);
    for (ll j = i; j < max; ++j) {
      // std::cout << i << ' ' << j << ' ' << cur_val << std::endl;
      cur_val = cur_val * 2 + (s[j] == '1');
      if (mp.find(cur_val) == mp.end()) {
        mp[cur_val] = {i, j};
      }
    }
  }
  return mp;
}

class Solution {
 public:
  std::vector<std::vector<int>> substringXorQueries(
      std::string s, std::vector<std::vector<int>>& queries) {
    auto mp = precompute(s);
    std::vector<std::vector<int>> res;
    for (auto const& q : queries) {
      auto const val = q[0] ^ q[1];
      if (mp.find(val) == mp.end()) {
        res.push_back({-1, -1});
      } else {
        int first = mp[val].first;
        int second = mp[val].second;
        res.push_back(std::vector<int>({first, second}));
      }
    }
    // std::cout << std::endl;
    return res;
  }
};
