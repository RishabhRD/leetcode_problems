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

ll mod_power(ll n, ll x, ll mod) {
  if (x == 0) return 1;
  auto ans = mod_power(n, x / 2, mod);
  ans = (ans * ans) % mod;
  if (x % 2) ans = (ans * n) % mod;
  return ans;
}

ll constexpr mod = 1e9 + 7;

class Solution {
 public:
  int monkeyMove(int n) { return (mod_power(2, n, mod) - 2 + mod) % mod; }
};
