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
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

constexpr ll mod = 1e9 + 7;

auto sieve(ll n) {
  std::vector<ll> spf(n + 1, 0);
  spf[1] = 1;
  for (int i = 2; i < n + 1; i++) spf[i] = i;

  for (int i = 4; i < n + 1; i += 2) spf[i] = 2;

  for (int i = 3; i * i < n + 1; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < n + 1; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
  return spf;
}

void add_to_cnt(ll x, std::vector<ll>& ret, std::vector<ll> const& spf) {
  while (x != 1) {
    ++ret[spf[x]];
    x = x / spf[x];
  }
}

void minum_cnt(ll x, std::vector<ll>& ret, std::vector<ll> const& spf) {
  while (x != 1) {
    --ret[spf[x]];
    x = x / spf[x];
  }
}

ll calc(std::string_view word, std::vector<ll> const& spf) {
  auto const n = std::size(word);
  std::vector<ll> cnt(n + 1, 0);
  for (ll i = 1; i <= n; ++i) {
    add_to_cnt(i, cnt, spf);
  }
  std::array<ll, 26> arr = {0};
  for (auto c : word) {
    ++arr[c - 'a'];
  }
  for (ll i = 0; i < 26; ++i) {
    for (ll j = 1; j <= arr[i]; ++j) minum_cnt(j, cnt, spf);
  }
  ll res = 1;
  for (ll i = 1; i <= n; ++i) {
    while (cnt[i] > 0) {
      res = (res * i) % mod;
      --cnt[i];
    }
  }
  return res;
}

auto precompute(ll n) {
  std::vector<ll> res(n + 1);
  res[0] = 1;
  for (ll i = 1; i <= n; ++i) {
    res[i] = (res[i - 1] * i) % mod;
  }
  return res;
}

class Solution {
 public:
  int countAnagrams(std::string s) {
    auto const n = std::size(s);
    auto const spf = sieve(n);
    std::istringstream iss(s);
    std::string word;
    ll res = 1;
    while (getline(iss, word, ' ')) {
      res = (res * calc(word, spf)) % mod;
    }
    return res;
  }
};
