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

class Solution {
 public:
  ll countPalindromes(std::string s) {
    auto const n = std::size(s);
    std::vector<std::vector<ll>> prefix;
    auto const nums = [&](auto i, auto a, auto b) -> ll {
      if (b < a) return 0;
      if (a == 0) return prefix[b][i];
      return prefix[b][i] - prefix[a - 1][i];
    };
    {
      std::vector<ll> nums(10);
      for (auto c : s) {
        ++nums[c - '0'];
        prefix.push_back(nums);
      }
    }
    std::vector<std::vector<std::vector<ll>>> p_comb;
    p_comb.push_back(std::vector(10, std::vector(10, 0ll)));
    for (ll i = 1; i < n; ++i) {
      auto cur = p_comb[i - 1];
      for (ll j = 0; j <= 9; ++j) {
        cur[j][s[i - 1] - '0'] += nums(j, 0, i - 2);
      }
      p_comb.push_back(std::move(cur));
    }
    std::vector<std::vector<std::vector<ll>>> s_comb(
        n, std::vector(10, std::vector(10, 0ll)));
    for (ll i = n - 2; i >= 0; --i) {
      s_comb[i] = s_comb[i + 1];
      for (ll j = 0; j <= 9; ++j) {
        s_comb[i][s[i + 1] - '0'][j] += nums(j, i + 2, n - 1);
      }
    }
    // for (ll i = 1; i < n - 1; ++i) {
    //   for (int a = 0; a <= 9; ++a) {
    //     for (int b = 0; b <= 9; ++b) {
    //       std::cout << i << ' ' << a << ' ' << b << ' ' << p_comb[i][a][b]
    //                 << ' ' << s_comb[i][b][a] << std::endl;
    //     }
    //   }
    // }
    ll ans = 0;
    constexpr static ll mod = 1e9 + 7;
    for (ll i = 1; i < n - 1; ++i) {
      for (ll a = 0; a <= 9; ++a) {
        for (ll b = 0; b <= 9; ++b) {
          ans = (ans + ((p_comb[i][a][b] * s_comb[i][b][a]) % mod)) % mod;
        }
      }
    }
    return ans;
  }
};
